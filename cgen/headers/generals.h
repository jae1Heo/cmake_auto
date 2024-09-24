#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <string>
#include <dirent.h>
#include <vector>
#include <fcntl.h>

#define GENERAL_ERROR_EXIT -1
//---------------folders---------------

// project name
#define PROJECT_NAME_LEN 128
#define PROJECT_NAME_LEN_OVERFLOW 224
#define PROJECT_FOLDER_CREATE_FAILED 225

// header folder
#define HEADER_FOLDER_CREATE_FAILED 344

// build folder
#define BUILD_FOLDER_CREATE_FAILED 442

// source folder
#define SOURCE_FOLDER_CREATE_FAILED 512

// undefined
#define UNDEFINED_FOLDER_CREATE_ERROR -1


//---------------data---------------

#define BUF_LEN 128
