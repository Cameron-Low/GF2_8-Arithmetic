#include "aes_gf28.h"
#include <iostream>

void print_element(aes_gf28_t a) {
    bool first = true;
    for (int i = 7; i >= 0; i--) {
        if (((a >> i) & 1) == 1) {
            if (first) {
                if (i == 0) {
                    std::cout << "1";
                } else {
                    std::cout << "x^" << i;
                }
                first = false;
            } else {
                if (i == 0) {
                    std::cout << " + 1";
                } else {
                    std::cout << " + x^" << i;
                }
            }
        }
    }
    std::cout << std::endl;
}

aes_gf28_t add(aes_gf28_t a, aes_gf28_t b) {
    return a ^ b;
}

aes_gf28_t sub(aes_gf28_t a, aes_gf28_t b) {
    return a ^ b;
}

aes_gf28_t mul(aes_gf28_t a, aes_gf28_t b) {
    aes_gf28_t temp = 0;
    for (int i = 7; i >= 0; i--) {
        temp = mulx(temp);
        if ((b >> i) & 1) temp = add(temp, a);
    }
    return temp;
}

// Multiply by x and reduce mod x^8 + x^4 + x^3 + x + 1
aes_gf28_t mulx(aes_gf28_t a) {
    if ((a & 0x80) == 0x80) return (a << 1) ^ 0x1b;
    return a << 1;
}

// Compute the inverse using Fermat's little theorem
aes_gf28_t inv(aes_gf28_t a) {
    aes_gf28_t t0 = a * a;
    aes_gf28_t t1 = t0 * a;
    t0 = mul(t0, t0); 
    t1 = mul(t0, t1);
    t0 = mul(t0, t0);
    t0 = mul(t1, t0); 
    t0 = mul(t0, t0);
    t1 = mul(t1, t0);
    t1 = mul(t1, t0);
    t0 = mul(t0, t0);
    t0 = mul(t0, t1);
    return mul(t0, t0);
}

aes_gf28_t div(aes_gf28_t a, aes_gf28_t b) {
    return mul(a, inv(b));
}

