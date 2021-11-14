#include <iostream>

class Solution {
public:
    int romanToInt(std::string s);
};

int main() {

    Solution sol;

    std::cout << "MMMCMXCIX = " << sol.romanToInt("MMMCMXCIX") << std::endl;
    std::cout << "CMXCIX = " << sol.romanToInt("CMXCIX") << std::endl;
    std::cout << "XCIX = " << sol.romanToInt("XCIX") << std::endl;
    std::cout << "IX = " << sol.romanToInt("IX") << std::endl;
    std::cout << "IV = " << sol.romanToInt("IV") << std::endl;
    std::cout << "III = " << sol.romanToInt("III") << std::endl;
    std::cout << "VII = " << sol.romanToInt("VII") << std::endl;

    return 0;
}

/* SOLUTION */

struct Sign {
    int8_t roman;
    int16_t decimal;

    Sign(int8_t roman, int16_t decimal) : roman(roman), decimal(decimal) {}
};

Sign signs[] = {
        Sign('M', 1000),
        Sign('D', 500),
        Sign('C', 100),
        Sign('L', 50),
        Sign('X', 10),
        Sign('V', 5),
        Sign('I', 1)
};

int Solution::romanToInt(std::string s) {

    int16_t res = 0;
    int8_t prev = -1;

    for (int8_t i = 0; i < s.size(); ++i) {

        for (int8_t j = 0; j < 7; ++j) {
            if(signs[j].roman == s[i]) {
                if(j < 5 && signs[j + 2].roman == prev) {
                    res += signs[j + 2].decimal * 8;
                    prev = -1;
                } else if(j < 6 && signs[j + 1].roman == prev) {
                    res += signs[j + 1].decimal * 3;
                    prev = -1;
                } else {
                    res += signs[j].decimal;
                    prev = signs[j].roman;
                }
            }
        }
    }
    return res;
}
