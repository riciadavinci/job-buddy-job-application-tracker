#pragma once

#include <string>
#include <optional>

namespace jobbuddy {

enum class ResponseCode : int {
    Success = 0,
    Failure,
    NetworkError,
    DatabaseError,
    DiskIOError,
    NotFoundError
};


template <typename Type>
struct Response {
private:    
    std::optional<Type> m_value;
public:
    std::string message;
    ResponseCode code;

    [[nodiscard]] static Response success(const Type& value, const std::string& message = "Success") {
        return {value, message, ResponseCode::Success};
    }

    [[nodiscard]] static Response success(Type&& value, const std::string& message = "Success") {
        return {std::move(value), message, ResponseCode::Success};
    }

    [[nodiscard]] static Response fail(const std::string& error_message, ResponseCode code = ResponseCode::Failure) {
        return {std::nullopt, error_message, code};
    }

    [[nodiscard]] bool ok() const {
        return m_value.has_value() && (code == ResponseCode::Success);
    }

    [[nodiscard]] const Type& value() const& { return m_value.value(); }
    [[nodiscard]] Type& value() & { return m_value.value(); }
    [[nodiscard]] Type&& value() && { return std::move(m_value).value(); }

private:
    // Private Constructor
    Response(std::optional<Type> val, std::string msg, ResponseCode c)
        : m_value {std::move(val)}, message {std::move(msg)}, code {c} {}
};

template <typename Type>
using RepositoryResponse = Response<Type>;

}