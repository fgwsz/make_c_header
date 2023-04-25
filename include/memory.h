#ifndef HF_MEMORY_H
#define HF_MEMORY_H
#ifdef __cplusplus
extern "C"{
#endif
#include<stddef.h> // size_t
extern void* memory_alloc(size_t size);
extern void  memory_free(void* ptr);
#ifdef __cplusplus
}
#endif
#endif//!HF_MEMORY_H
