#include <stdio.h>
#include <stdint.h>

void info(float num);

int main(void) {
    float num;
    printf("Enter a floating-point number: ");
    scanf("%f", &num);

    info(num);

    return 0;
}

void info(float num) {
    union {
        float f;
        uint32_t u;
    } data;

    data.f = num;

    int sign = (data.u >> 31) & 1;
    int exponent = ((data.u >> 23) & 0xFF) - 127;
    unsigned int mantissa = data.u & 0x7FFFFF;

    float mantissa_val = 1.0f;
    for (int i = 22; i >= 0; i--) {
        if (mantissa & (1u << i)) {
            mantissa_val += 1.0f / (1 << (23 - i));
        }
    }

    float reconstructed = mantissa_val * (1 << exponent);

    printf("\nSign bit: %c\n", sign ? '-' : '+');
    printf("Mantissa value: %.5f\n", mantissa_val - 1.0f);
    printf("Exponent value: %d\n", exponent);
    printf("Reconstructed value: (1.0+%.5f) * 2**%d = %f\n",
           mantissa_val - 1.0f, exponent, reconstructed);
}
