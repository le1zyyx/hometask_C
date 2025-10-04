#include "array_utils.h"
#include <limits.h>
int binary_search(const int *a, size_t n, int value) {
    size_t lo = 0, hi = n;
    while (lo < hi) {
        size_t mid = (lo + hi) / 2;
        if (a[mid] == value) return (int)mid;
        if (a[mid] < value)
            lo = mid + 1;
        else
            hi = mid;
    }
    return -1;
}
int array_max(const int *a, size_t n) {
    if (n == 0) return INT_MIN;
    int m = a[0];
    for (size_t i = 1; i < n; ++i)
        if (a[i] > m) m = a[i];
    return m;
}
int array_min(const int *a, size_t n) {
    if (n == 0) return INT_MAX;
    int m = a[0];
    for (size_t i = 1; i < n; ++i)
        if (a[i] < m) m = a[i];
    return m;
}
