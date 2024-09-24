cmake_minimum_required(VERSION 3.10)
project(cgen)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# you can add more here
file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(cgen main.cpp ${SRC_FILES})
target_include_directories(cgen PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)

