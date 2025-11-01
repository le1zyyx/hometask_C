#include "custom_getline.h"
#include <stdlib.h>
#include <string.h>

size_t custom_getline(char **lineptr, size_t *n, const char *source) {
    if (!lineptr || !n || !source)
        return -1;
    
    size_t len = strlen(source);
    
    if (*lineptr == NULL || *n < len + 1) {
        char* new_ptr = realloc(*lineptr, len + 1);
        if (!new_ptr)
            return -1;
        *lineptr = new_ptr;
        *n = len + 1;
    }
    
    strcpy(*lineptr, source);
    return (ssize_t)len;
}
