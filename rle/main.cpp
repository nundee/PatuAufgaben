#include <iostream>
#include <cassert>
#include "run_length.h"


int main() {
    //std::cout << "select mode: 0 = encode / 1 = decode\n";
    unsigned int mode;
    std::cin >> mode;

    if (mode == 0) {
        std::cout << "***";
        encode();
        std::cout <<"***";
    } else if (mode == 1) {
        std::cout << "***";
        decode();
        std::cout << "***";
    } else {
        std::cout << "unknown mode, must be 0 (encode) or 1 (decode)\n";
    }
    return 0;
}