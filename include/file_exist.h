#ifndef HF_FILE_EXIST_H
#define HF_FILE_EXIST_H
#include<stdbool.h> // bool
#ifdef __cplusplus
    extern "C" {
#endif
extern bool file_exist(char const* file_path);
#ifdef __cplusplus
    }
#endif
#endif
