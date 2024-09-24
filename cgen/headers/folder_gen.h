#pragma once
#include "generals.h"

class folder_generate{
    private:
        void create_folder(const char*);
        void folder_create_failed_log(const char*);
        char buffer[BUF_LEN] = {0,};
        std::vector<const char*>foldernames;
        
    public:
        folder_generate(const char*);
        void launch(const char*);
        ~folder_generate();

};