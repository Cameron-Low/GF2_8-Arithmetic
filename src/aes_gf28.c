#include "aes_gf28.h"

void print_aes_element(aes_gf28_t a) {
    bool first = true;
    for (int i = 7; i >= 0; i--) {
        if (((a >> i) & 1) == 1) {
            if (first) {
                if (i == 0) {
                    printf("1");
                } else {
                    printf("x^%d", i);
                }
                first = false;
            } else {
                if (i == 0) {
                    printf(" + 1");
                } else {
                    printf(" + x^%d", i);
                }
            }
        }
    }
    printf("\n");
}

aes_gf28_t aes_add(aes_gf28_t a, aes_gf28_t b) {
    return a ^ b;
}

aes_gf28_t aes_sub(aes_gf28_t a, aes_gf28_t b) {
    return a ^ b;
}

aes_gf28_t aes_mul(aes_gf28_t a, aes_gf28_t b) {
    aes_gf28_t temp = 0;
    for (int i = 7; i >= 0; i--) {
        temp = aes_mulx(temp);
        if ((b >> i) & 1) temp = aes_add(temp, a);
    }
    return temp;
}

// Multiply by x and reduce mod x^8 + x^4 + x^3 + x + 1
aes_gf28_t aes_mulx(aes_gf28_t a) {
    if ((a & 0x80) == 0x80) return (a << 1) ^ 0x1b;
    return a << 1;
}

// Compute the inverse using Fermat's little theorem
aes_gf28_t aes_inv(aes_gf28_t a) {
    aes_gf28_t t0 = aes_mul(a, a);
    aes_gf28_t t1 = aes_mul(t0, a);
    t0 = aes_mul(t0, t0); 
    t1 = aes_mul(t0, t1);
    t0 = aes_mul(t0, t0);
    t0 = aes_mul(t1, t0); 
    t0 = aes_mul(t0, t0);
    t1 = aes_mul(t1, t0);
    t1 = aes_mul(t1, t0);
    t0 = aes_mul(t0, t0);
    t0 = aes_mul(t0, t1);
    return aes_mul(t0, t0);
}

aes_gf28_t aes_div(aes_gf28_t a, aes_gf28_t b) {
    return aes_mul(a, aes_inv(b));
}

