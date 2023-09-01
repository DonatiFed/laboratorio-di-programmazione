# 'Google_test' is the subproject name

# 'lib' is the folder with Google Test sources
add_subdirectory(./lib/gtest)
set(gtest_SOURCE_DIR, ./lib/gtest/)
include_directories(${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR})
set(SOURCE_TEST_FILES TestUser.cpp ../User.h )

# 'Google_Tests_run' is the target name
# 'test1.cpp test2.cpp' are source files with tests
add_executable(runTests ${SOURCE_TEST_FILES})
target_link_libraries(runTests gtest gtest_main)