cmake_minimum_required(VERSION 3.20)


# === Including fixed-capacity-containers === #
include(FetchContent)

set(FETCHCONTENT_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../deps" CACHE STRING "FetchContent Root" FORCE)

FetchContent_Declare(
    fixed_capacity_containers
    GIT_REPOSITORY https://github.com/riciadavinci/fixed-capacity-containers.git
    GIT_TAG        develop
)

FetchContent_MakeAvailable(fixed_capacity_containers)
# =========================================== #

qt_standard_project_setup()

# Server
qt_add_executable(job_buddy 
    main.cpp
)

target_include_directories(job_buddy PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/core
    ${CMAKE_CURRENT_SOURCE_DIR}/job_application
    ${CMAKE_CURRENT_SOURCE_DIR}/company
    ${CMAKE_CURRENT_SOURCE_DIR}/application_file
    ${CMAKE_CURRENT_SOURCE_DIR}/tag
    ${CMAKE_CURRENT_SOURCE_DIR}/action_log
    ${CMAKE_CURRENT_SOURCE_DIR}/qml
)

qt_add_resources(job_buddy "qml"
    PREFIX "/"
    FILES
        qml/Main.qml
        qml/Home.qml
)


target_link_libraries(job_buddy
    PRIVATE
        Qt6::Core
        Qt6::Widgets
        Qt6::Qml
        Qt6::Quick
        fcc::fcc
)

set_target_properties(job_buddy PROPERTIES
    WIN32_EXECUTABLE FALSE
)
