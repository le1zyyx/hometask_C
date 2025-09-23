#include <stdio.h>
#include <stdint.h>
#include <math.h>

void info(float num);

int main(void) {
    float num;
    printf("Enter a floating-point number: ");
    scanf("%f", &num);

    info(num);
    
    return 0;
}

void info(float num) {
    union { float f; uint32_t u; } d;
    d.f = num;
    int sign = (d.u >> 31) & 1;
    int raw_exp = (d.u >> 23) & 0xFF;
    unsigned mantissa = d.u & 0x7FFFFF;

    if (raw_exp == 0 && mantissa == 0) {
        printf("Sign bit: %c\nMantissa value: 0.00000\nExponent value: 0\nReconstructed value: %c0.0\n",
               sign ? '-' : '+', sign ? '-' : '+');
        return;
    }
    if (raw_exp == 255 && mantissa == 0) {
        printf("Sign bit: %c\nMantissa value: N/A\nExponent value: INF\nReconstructed value: %cInfinity\n",
               sign ? '-' : '+', sign ? '-' : '+');
        return;
    }
    if (raw_exp == 255 && mantissa != 0) {
        printf("Sign bit: %c\nMantissa value: N/A\nExponent value: NaN\nReconstructed value: NaN\n",
               sign ? '-' : '+');
        return;
    }

    float m = 0.0f;
    for (int i = 22; i >= 0; i--) if (mantissa & (1u << i)) m += 1.0f / (1 << (23 - i));

    int exp; float rec;
    if (raw_exp == 0) { exp = -126; rec = powf(-1, sign) * m * powf(2, exp); }
    else { exp = raw_exp - 127; rec = powf(-1, sign) * (1.0f + m) * powf(2, exp); }

    printf("Sign bit: %c\nMantissa value: %.5f\nExponent value: %d\nReconstructed value: %f\n",
           sign ? '-' : '+', m, exp, rec);
}
