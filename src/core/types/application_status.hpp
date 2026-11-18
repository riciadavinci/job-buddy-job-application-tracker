#pragma once

namespace jobbuddy {

enum class ApplicationStatus : int {
    Shortlisted = 0,
    Applied,
    Rejected,
    InterviewRoundGeneric,
    InterviewRoundTechnical,
    InterviewRoundHR,
    Ghosted,
    JobOffer,
    OfferAccepted,
    OfferRejected
};

}