#pragma once

#include <string>
#include <chrono>
#include <types.hpp>

namespace jobbuddy {

struct JobApplication {
    int id;                                         // Primary Key, Auto-increment
    std::string title;                              // Not Nullable
    int company_id;                                 // Foreign Key, Company.id
    ApplicationStatus status;                       // underlying int value
    std::string description;                        // Nullable
    std::string notes;                              // Nullable
    int resume_file_id;                             // Foreign Key, ApplicationFile.id
    int cover_letter_file_id;                       // Foreign Key, ApplicationFile.id
    std::chrono::sys_seconds created_on{};          // 
    std::chrono::sys_seconds modified_on{};         // 
};

}