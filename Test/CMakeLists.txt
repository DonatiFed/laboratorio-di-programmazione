cmake_minimum_required(VERSION 3.5)

add_subdirectory(./lib/gtest)
set(gtest_SOURCE_DIR, ./lib/gtest/)
include_directories(${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR})

set(SOURCE_TEST_FILES runAllTests.cpp TestList.cpp TestItem.cpp TestUser.cpp TestListUpdate.cpp)
add_executable(runTests ${SOURCE_TEST_FILES})
target_link_libraries(runTests gtest gtest_main core )
