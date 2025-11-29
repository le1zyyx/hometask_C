#ifndef __E4_AUTH_H__
#define __E4_AUTH_H__

#include <stdbool.h>
#include <stdint.h>

#define KEY_SIZE 16

void init();
void sign(const uint8_t *hash, uint8_t *mac);
bool check_sign(const uint8_t *hash, const uint8_t *mac);

#endif