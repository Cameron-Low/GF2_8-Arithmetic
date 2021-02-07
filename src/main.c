#include "aes_gf28.h"

int main() {
    print_aes_element(0x3b);
    print_aes_element(0x33);
    print_aes_element(aes_mul(0x3b, 0x33));
    return 0;
}
