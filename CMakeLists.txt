cmake_minimum_required(VERSION 3.22)
project(IBag151)
set(CMAKE_CXX_STANDARD 11)

# Camera Tests
message("Testing Enabled")
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/tests/testCamera.cpp ${PROJECT_SOURCE_DIR}/include/*.cpp)

add_subdirectory(lib/googletest)

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(runTestCamera ${TEST_SRC_FILES})
target_link_libraries(runTestCamera gtest gtest_main)
add_test(UnitTests runTestCamera)

# IMovement Tests
message("Testing Enabled")
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/tests/testMovement.cpp ${PROJECT_SOURCE_DIR}/include/*.cpp)

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(runTestMovement ${TEST_SRC_FILES})
target_link_libraries(runTestMovement gtest gtest_main)
add_test(UnitTests runTestMovement)

# Package Tests
message("Testing Enabled")
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/tests/testPackage.cpp ${PROJECT_SOURCE_DIR}/include/*.cpp)

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(runTestPackage ${TEST_SRC_FILES})
target_link_libraries(runTestPackage gtest gtest_main)
add_test(UnitTests runTestPackage)

# Drone Tests
message("Testing Enabled")
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/tests/testDrone.cpp ${PROJECT_SOURCE_DIR}/include/*.cpp)

enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(runTestDrone ${TEST_SRC_FILES})
target_link_libraries(runTestDrone gtest gtest_main)
add_test(UnitTests runTestDrone)