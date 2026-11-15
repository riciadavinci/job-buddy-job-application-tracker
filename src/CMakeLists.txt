cmake_minimum_required(VERSION 3.20)

qt_standard_project_setup()

# Server
qt_add_executable(JobBuddy 
    main.cpp
)

target_include_directories(JobBuddy PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/core
    ${CMAKE_CURRENT_SOURCE_DIR}/ui
)

qt_add_resources(JobBuddy "qml"
    PREFIX "/"
    FILES
        ui/Main.qml
        ui/Home.qml
)


target_link_libraries(JobBuddy
    PRIVATE
        Qt6::Core
        Qt6::Widgets
        Qt6::Qml
        Qt6::Quick
)

set_target_properties(JobBuddy PROPERTIES
    WIN32_EXECUTABLE FALSE
)
