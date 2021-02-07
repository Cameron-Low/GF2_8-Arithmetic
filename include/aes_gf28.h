#ifndef __AES_GF28_H_
#define __AES_GF28_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

typedef uint_fast8_t aes_gf28_t;

void print_element(aes_gf28_t a);

aes_gf28_t add(aes_gf28_t a, aes_gf28_t b);
aes_gf28_t sub(aes_gf28_t a, aes_gf28_t b);
aes_gf28_t mul(aes_gf28_t a, aes_gf28_t b);
aes_gf28_t mulx(aes_gf28_t a);
aes_gf28_t inv(aes_gf28_t a);
aes_gf28_t div(aes_gf28_t a, aes_gf28_t b);

#endif
