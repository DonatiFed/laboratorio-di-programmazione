cmake_minimum_required(VERSION 3.23)
project(untitled18)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled18 main.cpp User.h list.h Item.h Item.cpp list.cpp Subject.h Observer.h ObjectNumberUpdate.h ObjectNumberUpdate.cpp ObjectToBuyUpdate.cpp ObjectToBuyUpdate.h User.cpp Test/TestUser.cpp)
add_subdirectory(Test)