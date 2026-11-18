#pragma once

#include <string>
#include <chrono>
#include <types.hpp>

namespace jobbuddy {

struct ApplicationFile {
    int id;                                     // PK, Auto-Increment
    std::string name;                           // Non-nullable
    ApplicationFileType file_type;              // ApplicationFileType Enum (int)
    std::string content;                        // Nullable
    std::chrono::sys_seconds created_on{};      // 
    std::chrono::sys_seconds modified_on{};     // 
};

}