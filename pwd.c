#include"pwd.h"
#if defined(WIN32) || defined(_WIN32) || defined(_WIN32_) || defined(WIN64) || defined(_WIN64) || defined(_WIN64_)
    #include<windows.h>
    void pwd(char* buffer,size_t byte_size){
        GetCurrentDirectory(byte_size,(CHAR*)buffer);
    }
#elif defined(__linux__)
    #include<unistd.h>
    void pwd(char* buffer,size_t byte_size){
        getcwd(buffer,byte_size);
    }
#endif
