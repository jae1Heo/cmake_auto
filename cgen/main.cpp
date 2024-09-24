#include "headers/file_managements.h"

int main(int argc, char* argv[]) {
    if(argc != 2) {
        std::cerr<<"Usage: ./cgen projectname"<<std::endl;
        exit(GENERAL_ERROR_EXIT);
    }
    folder_generate folder(argv[1]);
    file_generate* file = new file_generate();
    return 0;
}