#ifndef __AES_GF28_H_
#define __AES_GF28_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

typedef uint_fast8_t aes_gf28_t;

void print_aes_element(aes_gf28_t a);

aes_gf28_t aes_add(aes_gf28_t a, aes_gf28_t b);
aes_gf28_t aes_sub(aes_gf28_t a, aes_gf28_t b);
aes_gf28_t aes_mul(aes_gf28_t a, aes_gf28_t b);
aes_gf28_t aes_mulx(aes_gf28_t a);
aes_gf28_t aes_inv(aes_gf28_t a);
aes_gf28_t aes_div(aes_gf28_t a, aes_gf28_t b);

#endif
