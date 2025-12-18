#include <string.h>

void* memcpy(void* restrict dstptr, const void* restrict srcptr, size_t size){
    unsigned char *ds = (unsigned char *)dstptr;
    const unsigned char *src = (const unsigned char *)srcptr;
    for(size_t i = 0; i < size; i++){
        ds[i] = src[i];
    }
    return dstptr;
}

