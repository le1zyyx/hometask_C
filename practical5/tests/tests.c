#include "array_utils.h"
#include <assert.h>
#include <limits.h>
int main(void) {
    int a1[] = {1, 3, 5, 7, 9};
    assert(binary_search(a1, 5, 1) == 0);
    assert(binary_search(a1, 5, 9) == 4);
    assert(binary_search(a1, 5, 6) == -1);
    assert(binary_search(a1, 0, 1) == -1);
    assert(binary_search(a1, 1, 3) == -1);
    assert(binary_search(a1, 1, 1) == 0);
    assert(array_max(a1, 5) == 9);
    assert(array_max(a1, 0) == INT_MIN);
    assert(array_min(a1, 5) == 1);
    assert(array_min(a1, 0) == INT_MAX);
    return 0;
}
