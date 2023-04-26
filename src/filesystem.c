#include"filesystem.h"
#if defined(WIN32) || defined(_WIN32) || defined(_WIN32_) || defined(WIN64) || defined(_WIN64) || defined(_WIN64_)
    #include<direct.h> // _getcwd mkdir
    #include<io.h> // _access
    char* filesystem_getCurrentDirPath(){
        return _getcwd(NULL,0);
    }
    bool filesystem_pathExist(char const* path){
        return (bool)(_access(path,0)!=-1);
    }
    void  filesystem_createDir(char const* dir_path){
        if(!filesystem_pathExist(dir_path)){
            mkdir(dir_path);
        }
    }
#elif defined(__linux__)
    #include<unistd.h> // get_current_dir_name access F_OK
    // mkdir
    #include <sys/stat.h>
    #include <sys/types.h>
    char* filesystem_getCurrentDirPath(){
        return get_current_dir_name();
    }
    bool filesystem_pathExist(char const* path){
        return (bool)(access(path,F_OK)==0);
    }
    void  filesystem_createDir(char const* dir_path){
        if(!filesystem_pathExist(dir_path)){
            mkdir(dir_path,S_IRWXU);
        }
    }
#endif
#include<stdio.h> // fopen fclose FILE
void  filesystem_createFile(char const* file_path){
    if(!filesystem_pathExist(file_path)){
        FILE* stream=fopen(file_path,"w");
        if(stream!=NULL){
            fclose(stream);
        }
    }
}
