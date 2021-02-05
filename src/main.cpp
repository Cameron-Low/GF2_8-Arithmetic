#include <iostream>
#include "aes_gf28.h"

int main() {
    std::cout << "Testing" << std::endl;
    print_element(0x3b);
    print_element(0x33);
    print_element(mul(0x3b, 0x33));
    return 0;
}
