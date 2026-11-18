#pragma once

#include <string>
#include <optional>
#include <types.hpp>

namespace jobbuddy {

struct ActionLog {
    int id;                                     // PK, Auto-Increment
    int entity_id;                              // FK, Entity.id (Entity = Company, JobApplication, ApplicationFile, Tag)
    EntityType entity_type;                     // Enum (int)
    ActionType action_type;                     // Enum (int)
    std::optional<std::string> old_data;        // 
    std::optional<std::string> new_data;        // 
}; 

}