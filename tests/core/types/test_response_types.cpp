#include <gtest/gtest.h>

#include <types/response_types.hpp>

#include <optional>
#include <string>
#include <memory>

namespace jobbuddy::testing {

struct DummyItem {
    int id;
    std::string text_field;

    bool operator==(const DummyItem& other) const {
        return (id == other.id) && (text_field == other.text_field);
    }
};


TEST(ResponseTest, DefaultSuccessResponseMovedValue) {
    auto response = Response<int>::success(10);

    ASSERT_TRUE(response.ok());
    EXPECT_EQ(response.value(), 10);
    EXPECT_EQ(response.message, "Success");
    EXPECT_EQ(response.code, ResponseCode::Success);
}

TEST(ResponseTest, DefaultSuccessResponseConstReferenceValue) {
    auto item = DummyItem {5, "Test String"};
    auto response = Response<DummyItem>::success(item);
    
    ASSERT_TRUE(response.ok());
    EXPECT_EQ(response.value(), item);
    EXPECT_EQ(response.message, "Success");
    EXPECT_EQ(response.code, ResponseCode::Success);
}

TEST(ResponseTest, SuccessResponseMoveOnlyType) {
    auto ptr = std::make_unique<int>(42);
    auto response = Response<std::unique_ptr<int>>::success(std::move(ptr));
    
    ASSERT_TRUE(response.ok());
    EXPECT_EQ(*(response.value()), 42);
    EXPECT_EQ(response.message, "Success");
    EXPECT_EQ(response.code, ResponseCode::Success);
}

TEST(ResponseTest, SuccessResponseWithMessage) {
    auto response = Response<int>::success(50, "It Works!");

    ASSERT_TRUE(response.ok());
    EXPECT_EQ(response.value(), 50);
    EXPECT_EQ(response.message, "It Works!");
    EXPECT_EQ(response.code, ResponseCode::Success);
}

TEST(ResponseTest, SuccessResponseWithMessageMoveOnly) {
    auto ptr = std::make_unique<uint64_t>(100UL);
    auto response = Response<std::unique_ptr<uint64_t>>::success(std::move(ptr), "Testing Move Only with Message");

    ASSERT_TRUE(response.ok());
    EXPECT_EQ(*(response.value()), 100UL);
    EXPECT_EQ(response.message, "Testing Move Only with Message");
    EXPECT_EQ(response.code, ResponseCode::Success);
}

TEST(ResponseTest, FailResponseDefaultCode) {
    auto response = Response<int>::fail("Failed");

    ASSERT_FALSE(response.ok());
    EXPECT_EQ(response.message, "Failed");
    EXPECT_EQ(response.code, ResponseCode::Failure);
}

TEST(ResponseTest, FailResponseCustomCode) {
    auto response = Response<int>::fail("Failed with custom code", ResponseCode::NetworkError);

    ASSERT_FALSE(response.ok());
    EXPECT_EQ(response.message, "Failed with custom code");
    EXPECT_EQ(response.code, ResponseCode::NetworkError);
}

}