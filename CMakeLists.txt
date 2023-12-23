cmake_minimum_required(VERSION 3.23)
project(untitled_18)

set(CMAKE_CXX_STANDARD 14)


add_subdirectory(test)

set(SOURCE_FILES User.h User.cpp Subject.h Observer.h Item.h Item.cpp ObjectNumberUpdate.h ObjectNumberUpdate.cpp ObjectToBuyUpdate.h ObjectToBuyUpdate.cpp list.h list.cpp ListUpdate.cpp ListUpdate.h)
add_executable(untitled_18 main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(untitled_18 core)