#pragma once
#include "generals.h"

class file_generate{
    private:
        void generate_cmakelist();
        void generate_main_cpp();
        std::vector<const char*>cm_codes;
    public:
        file_generate();
        void launch();
        ~file_generate();
};