#include"string_concat.h"
#include<stddef.h> // size_t
#include<string.h> // strlen strcat
#include"memory.h" // memory_alloc
static size_t local_string_length(char const* str){
    if(str==NULL){
        return 0;
    }
    return strlen(str);
}
static void local_string_cat(char* str_this,char const* str_append){
    if(local_string_length(str_append)==0){
        return;
    }
    strcat(str_this,str_append);
}
char* string_concat(char const* str1,char const* str2){
    size_t ret_byte_size=sizeof(char)*(local_string_length(str1)+local_string_length(str2)+1);
    char* ret=(char*)memory_alloc(ret_byte_size);
    local_string_cat(ret,str1);
    local_string_cat(ret,str2);
    return ret;
}
