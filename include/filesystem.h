#ifndef __HF_FILESYSTEM_H__
#define __HF_FILESYSTEM_H__
/* include header file */
#include<stdbool.h> // bool
#ifdef __cplusplus
    extern "C"{
#endif // __cplusplus
/* decl public interface */
extern char* filesystem_getCurrentDirPath();
extern bool  filesystem_pathExist(char const* path);
extern void  filesystem_createDir(char const* dir_path);
extern void  filesystem_createFile(char const* file_path);
#ifdef __cplusplus
    }
#endif // __cplusplus
#endif // !__HF_FILESYSTEM_H__
