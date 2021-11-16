#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <map>

class Solution {
public:
    long long interchangeableRectangles(std::vector<std::vector<int>> &rectangles);
};

int main() {


    std::vector<std::vector<int>> rectangles = {{4,  8},
                                                {3,  6},
                                                {10, 20},
                                                {15, 30}};

    Solution sol;
    std::cout << sol.interchangeableRectangles(rectangles) << std::endl;

    return 0;
}

/* SOLUTION */

long long Solution::interchangeableRectangles(std::vector<std::vector<int>> &rectangles) {

    std::map<std::pair<int, int>, int32_t> map;

    for (int i = 0; i < rectangles.size(); ++i) {
        std::vector<int> rect = rectangles[i];
        int gcd = std::__gcd(rect[0], rect[1]);
        std::pair<int, int> key = {rect[0] / gcd, rect[1] / gcd};
        map[key]++;
    }

    long long res = 0;
    for (const auto &item: map) {
        if (item.second > 1) {
            uint64_t x = item.second;
            res += ((x * (x - 1)) >> 1);
        }
    }

    return res;
}
