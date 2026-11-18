#pragma once

#include <string>

namespace jobbuddy {

struct Company {
    int id;                 // Primary Key, Auto-increment
    std::string name;       // Not Nullable
};

}