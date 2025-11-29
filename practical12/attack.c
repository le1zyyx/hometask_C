#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "auth.h"

#define SAMPLES 1000
#define TRIALS 20

int main() {
    init();

    uint8_t hash[KEY_SIZE];
    uint8_t mac[KEY_SIZE] = {0};
    uint8_t recovered_mac[KEY_SIZE] = {0};

    printf("Hash: ");
    for (int i = 0; i < KEY_SIZE; ++i) {
        hash[i] = rand() % 256;
        printf("%02x ", hash[i]);
    }
    printf("\n");

    printf("Starting optimized timing attack...\n");

    for (int i = 0; i < KEY_SIZE; ++i) {
        clock_t best_execution_time = 0;
        uint8_t best_byte = 0;

        for (int guess = 0; guess < 256; ++guess) {
            mac[i] = (uint8_t)guess;

            clock_t min_time = -1;

            for (int t = 0; t < TRIALS; ++t) {
                clock_t start = clock();
                for (int j = 0; j < SAMPLES; ++j) {
                    check_sign(hash, mac);
                }
                clock_t end = clock();
                clock_t diff = end - start;

                if (min_time == (clock_t)-1 || diff < min_time) {
                    min_time = diff;
                }
            }

            if (min_time > best_execution_time) {
                best_execution_time = min_time;
                best_byte = (uint8_t)guess;
            }
        }

        mac[i] = best_byte;
        recovered_mac[i] = best_byte;
        
        printf("Recovered byte %d: %02x (score: %ld)\n", i, best_byte, best_execution_time);
    }

    printf("\nRecovered MAC: ");
    for (int i = 0; i < KEY_SIZE; ++i) {
        printf("%02x ", recovered_mac[i]);
    }
    printf("\n");

    printf("Recovered secret: ");
    for (int i = 0; i < KEY_SIZE; ++i) {
        uint8_t secret_byte = hash[i] ^ recovered_mac[i];
        printf("%02x ", secret_byte);
    }
    printf("\n");

    return 0;
}