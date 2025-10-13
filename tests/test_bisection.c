#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "bisection.h"

int main() {
    double r;

    r = find_intersection(2.0, 1.0, -5.0, 5.0, 1e-6);
    assert(fabs(r + 1.0) < 1e-5);

    r = find_intersection(-1.0, 3.0, 0.0, 5.0, 1e-8);
    assert(fabs(r - 1.5) < 1e-7);

    r = find_intersection(0.5, -2.0, -10.0, 0.0, 1e-6);
    assert(fabs(r + 4.0) < 1e-5);

    r = find_intersection(1.0, 0.0, -100.0, 100.0, 1e-6);
    assert(r >= -100.0 && r <= 100.0);

    r = find_intersection(0.5, 2.0, 3.0, 3.0, 1e-6);
    assert(fabs(r - 3.0) < 1e-5);

    r = find_intersection(2.0, 1.0, 10.0, 15.0, 1e-6);

    r = find_intersection(3.0, 12.0, -10.0, 0.0, -5.0);

    r = find_intersection(NAN, 1.0, 0.0, 5.0, 1e-6);

    printf("all bisection tests passed\n");
    return 0;
}