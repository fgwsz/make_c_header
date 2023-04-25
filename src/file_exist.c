#include"file_exist.h"
#include<stdio.h>
bool file_exist(char const* file_path){
    FILE* file=fopen(file_path,"r");
    bool ret=false;
    if (file!=NULL) {
        fclose(file);
        ret=true;
    }
    return ret;
}
