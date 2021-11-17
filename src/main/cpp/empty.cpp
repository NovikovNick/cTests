#include <iostream>
#include <bitset>

uint64_t convert(uint32_t a, uint32_t b) {
    return (uint64_t) a << 32 | b & 0xFFFFFFFFL;
}

std::pair<uint32_t, uint32_t> convert(uint64_t c) {
    return {(uint32_t) (c >> 32), (uint32_t) c};
}


int main() {
    uint32_t a = 4;
    uint32_t b = 100000;
    uint64_t c = convert(a, b);
    std::pair<uint32_t, uint32_t> pair = convert(c);

    std::cout << std::bitset<32>(a).to_string() << std::bitset<32>(b).to_string()  << std::endl;
    std::cout << std::bitset<64>(c).to_string() << std::endl;
    std::cout << std::bitset<32>(pair.first).to_string() << std::bitset<32>(pair.second).to_string()  << std::endl;
    std::cout << pair.first << '\t' <<  pair.second  << std::endl;

    return 0;
}

/* SOLUTION */

