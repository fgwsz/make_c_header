#ifndef __HF_STRING_CONCAT_H__
#define __HF_STRING_CONCAT_H__
/* include header file */

#ifdef __cplusplus
    extern "C"{
#endif // __cplusplus
/* decl public interface */
// please use free() to release the result
extern char* string_concat(char const* str1,char const* str2);
#ifdef __cplusplus
    }
#endif // __cplusplus
#endif // !__HF_STRING_CONCAT_H__
