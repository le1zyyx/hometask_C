#include <stdio.h>
#include "bisection.h"

int main() {
    double a, b, left, right, accuracy;
    int iterations = 0;
    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("left: ");
    scanf("%lf", &left);
    printf("right: ");
    scanf("%lf", &right);
    printf("accuracy: ");
    scanf("%lf", &accuracy);
    double result = find_intersection(a, b, left, right, accuracy);
    printf("x = %.6lf\niterations = %d\n", result, iterations);
    return 0;
}
