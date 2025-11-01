#ifndef CUSTOM_GETLINE_H
#define CUSTOM_GETLINE_H
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

size_t custom_getline(char **lineptr, size_t *n, const char *source);

#endif
