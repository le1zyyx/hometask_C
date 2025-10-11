#include <stdio.h>
#include <math.h>

static double h(double x, double a, double b) {
    return x - (a * x + b);
}

double find_intersection(double a, double b, double left, double right, double eps) {
    if (eps <= 0 || isnan(a) || isnan(b) || isnan(left) || isnan(right) || isnan(eps)) {
        printf("0\n");
        return left;
    }
    if (left > right) {
        double t = left;
        left = right;
        right = t;
    }
    if (fabs(right - left) < 1e-15) {
        printf("0\n");
        return left;
    }
    double fl = h(left, a, b);
    double fr = h(right, a, b);
    if (fl * fr > 0) {
        printf("0\n");
        return left;
    }
    int iterations = 0;
    while ((right - left) > eps) {
        double mid = (left + right) / 2.0;
        double fm = h(mid, a, b);
        if (fabs(fm) < 1e-15) {
            printf("%d\n", iterations + 1);
            return mid;
        }
        if (fl * fm <= 0) {
            right = mid;
            fr = fm;
        } else {
            left = mid;
            fl = fm;
        }
        iterations++;
    }
    printf("%d\n", iterations);
    return (left + right) / 2.0;
}
