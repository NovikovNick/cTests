#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>

class Solution {
public:
    std::string maxValue(std::string n, int x);
};

int main() {

    Solution sol;
    // std::cout << sol.maxValue("469975787943862651173569913153377", 3) << std::endl;
    // std::cout << "4699757879438632651173569913153377" << std::endl;
    std::cout << sol.maxValue("3862", 3) << std::endl;
    std::cout << "38632" << std::endl;
    return 0;
}

/* SOLUTION */
std::string Solution::maxValue(std::string n, int x) {

    bool negative = n[0] == '-';
    int32_t pos = negative ? 1 : 0;

    int32_t t;
    for (; pos < n.size(); pos++) {

        if (negative) {
            if((n[pos] - 48) > x) {
                break;
            }
        } else {
            if((n[pos] - 48) < x) {
                break;
            }
        }
    }

    n.insert(pos, 1, x + 48);

    return n;
}