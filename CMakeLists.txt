cmake_minimum_required(VERSION 3.10)
project(toros)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    source/commands/left_command.hpp
    source/commands/left_command.cpp
    source/commands/move_command.hpp
    source/commands/move_command.cpp
    source/commands/place_command.hpp
    source/commands/place_command.cpp
    source/commands/report_command.hpp
    source/commands/report_command.cpp
    source/commands/right_command.hpp
    source/commands/right_command.cpp
    source/utils/tokenizer.hpp
    source/utils/tokenizer.cpp
    source/command.hpp
    source/command_factory.hpp
    source/command_factory.cpp
    source/model.hpp
    source/model.cpp)

set(APP
    source/main.cpp)

set(TESTS
    test/utils/tokenizer_tests.cpp
    test/main.cpp)

include_directories(source)

# Library
add_library(toros ${SOURCES})

# Application
add_executable(toros_app ${APP})
target_link_libraries(toros_app toros)

# Tests
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(toros_tests ${TESTS})
target_link_libraries(toros_tests toros ${GTEST_BOTH_LIBRARIES} pthread)
