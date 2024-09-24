#include "folder_gen.h"

folder_generate::folder_generate(const char* pjn) {
    if(strlen(pjn) > PROJECT_NAME_LEN) {
        std::cout<<"project name is too long!"<<std::endl;
        exit(PROJECT_NAME_LEN_OVERFLOW);
    }

    if(mkdir(pjn, 0777) == -1) {
        std::cout<<"cannot create project folder."<<std::endl;
        exit(PROJECT_FOLDER_CREATE_FAILED);
    }
    this->foldernames.push_back("headers");
    this->foldernames.push_back("build");
    this->foldernames.push_back("src");

    launch(pjn);
}

void folder_generate::create_folder(const char* foldername) {
    if(mkdir(foldername, 0777) == -1) {
        this->folder_create_failed_log(foldername);
    }
}

void folder_generate::folder_create_failed_log(const char* foldername) {
    if(strcmp("headers", foldername) != 0) {
        std::cout<<"f:"<<HEADER_FOLDER_CREATE_FAILED<<std::endl;
    }
    else if(strcmp("build", foldername) != 0) {
        std::cout<<"f:"<<BUILD_FOLDER_CREATE_FAILED<<std::endl;
    }
    else if(strcmp("src", foldername) != 0) {
        std::cout<<"f:"<<SOURCE_FOLDER_CREATE_FAILED<<std::endl;
    }
    else{
        std::cout<<"f:"<<UNDEFINED_FOLDER_CREATE_ERROR<<std::endl;
    }
}

void folder_generate::launch(const char* pjn) {
    if(getcwd(this->buffer, sizeof(char)*BUF_LEN) == NULL) {
        std::cerr<<"cannot get the current directory"<<std::endl;
        exit(GENERAL_ERROR_EXIT);
    }
    strcat(this->buffer, "/");
    strcat(this->buffer, pjn);
    chdir(this->buffer);

    memset((void*)this->buffer, 0, sizeof(char)*BUF_LEN);
    for(const char* i : this->foldernames) {
        this->create_folder(i);
    }
    
}

folder_generate::~folder_generate() {

}