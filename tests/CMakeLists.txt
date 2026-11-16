cmake_minimum_required(VERSION 3.20)

include(FetchContent)

set(FETCHCONTENT_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../deps" CACHE STRING "FetchContent Root" FORCE)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.15.2
)

set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(job_buddy_test_runner
    test_main.cpp
)

target_link_libraries(job_buddy_test_runner PRIVATE GTest::gtest_main)

target_compile_features(job_buddy_test_runner PRIVATE cxx_std_20)

include(GoogleTest)
gtest_discover_tests(job_buddy_test_runner)

option(JOB_BUDDY_USE_ASAN "Enable Address and Undefined Behaviour Sanitizers" OFF)
option(JOB_BUDDY_USE_TSAN "Enable Thread Sanitizer" OFF)
option(JOB_BUDDY_ENABLE_CLANG_TIDY "Enable Clang-Tidy static analysis" OFF)

if(JOB_BUDDY_USE_ASAN AND JOB_BUDDY_USE_TSAN)
    message(FATAL_ERROR "JOB_BUDDY_USE_ASAN and JOB_BUDDY_USE_TSAN cannot be enabled at the same time!")
endif()

if(JOB_BUDDY_USE_ASAN)
    if(MSVC)
        target_compile_options(job_buddy_test_runner PRIVATE /fsanitize=address)
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|CLANG")
        target_compile_options(job_buddy_test_runner PRIVATE
            -fsanitize=address,undefined
            -fno-omit-frame-pointer
            -g
        )
        target_link_options(job_buddy_test_runner PRIVATE -fsanitize=address,undefined)
    endif()
endif()

if(JOB_BUDDY_USE_TSAN)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|CLANG")
        target_compile_options(job_buddy_test_runner PRIVATE
            -fsanitize=thread
            -fno-omit-frame-pointer
            -g
        )
        target_link_options(job_buddy_test_runner PRIVATE -fsanitize=thread)
    else()
        message(WARNING "Thread Sanitizer (TSan) is only supported on GCC and Clang.")
    endif()
endif()

if (JOB_BUDDY_ENABLE_CLANG_TIDY)
    find_program(CLANG_TIDY_EXE NAMES clang-tidy)
    if(CLANG_TIDY_EXE)
        set_target_properties(job_buddy_test_runner PROPERTIES
            CXX_CLANG_TIDY "${CLANG_TIDY_EXE};-warnings-as-errors=*"
        )
        message(STATUS "Clang-Tidy enabled for job_buddy_test_runner")
    else()
        message(WARNING "JOB_BUDDY_ENABLE_CLANG_TIDY was requested, but ${CLANG_TIDY_EXE} executable was not found.")
    endif()
endif()