#include "file_gen.h"
file_generate::file_generate() {
    // this is kind of primitive way.
    this->cm_codes.push_back("cmake_minimum_required(VERSION 3.10)\n");
    this->cm_codes.push_back("project(projectname)\n");
    this->cm_codes.push_back("set(CMAKE_CXX_STANDARD 17)\n");
    this->cm_codes.push_back("set(CMAKE_CXX_STANDARD_REQUIRED ON)\n");
    this->cm_codes.push_back("# you can add more here\n");
    this->cm_codes.push_back("file(GLOB_RECURSE SRC_FILES src/*.cpp)\n");
    this->cm_codes.push_back("add_executable(projectname main.cpp ${SRC_FILES})\n");
    this->cm_codes.push_back("target_include_directories(projectname PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)\n");

    launch();
}

void file_generate::generate_cmakelist() {
    int fd = open("CMakeLists.txt", O_CREAT | O_WRONLY, 0777);
    for(const char* i : this->cm_codes) {
        write(fd, i, strlen(i));
    }

    close(fd);
}

void file_generate::generate_main_cpp() {
    int fd = open("main.cpp", O_CREAT, 0777);
    close(fd);
}

void file_generate::launch() {
    this->generate_main_cpp();
    this->generate_cmakelist();
}

file_generate::~file_generate() {

}