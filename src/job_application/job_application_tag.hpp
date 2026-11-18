#pragma once

namespace jobbuddy {

struct JobApplicationTag {
    int job_application_id;             // FK, JobApplication.id
    int tag_id;                         // FK, Tag.id
};

}