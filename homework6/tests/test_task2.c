#include "custom_getline.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    
    const char *test1 = "Hello, world!";
    nread = custom_getline(&line, &len, test1);
    assert(nread == (ssize_t)strlen(test1));
    assert(strcmp(line, test1) == 0);
    printf("Test 1 passed\n");
    
    const char *test2 = "";
    nread = custom_getline(&line, &len, test2);
    assert(nread == 0);
    assert(strcmp(line, test2) == 0);
    printf("Test 2 passed\n");
    
    const char *test3 = "Another string";
    nread = custom_getline(&line, &len, test3);
    assert(nread == (ssize_t)strlen(test3));
    assert(strcmp(line, test3) == 0);
    printf("Test 3 passed\n");
    
    free(line);
    printf("\nAll tests passed1!\n");
    sleep(1);
    return 0;
}
