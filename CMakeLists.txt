cmake_minimum_required(VERSION 3.16)

project(02_lab)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(02_lab_logic
    src/array.cpp
    src/four.cpp
)

add_executable(02_lab_app src/main.cpp)
target_link_libraries(02_lab_app PRIVATE 02_lab_logic)

enable_testing()
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(run_tests tests/test_array.cpp tests/test_four.cpp)
target_link_libraries(run_tests PRIVATE gtest_main 02_lab_logic)
add_test(NAME unit_tests COMMAND run_tests)