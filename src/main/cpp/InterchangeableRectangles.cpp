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

    std::vector<std::vector<int>> rectangles = {
            {15,4},{21,33},{78,56},{71,33},{13,27},{39,21},{79,52},{37,3},{49,71},{67,58},
            {25,34},{24,12},{35,38},{53,63},{74,56},{3,29},{30,23},{9,22},{18,44},{28,7},
            {3,51},{45,69},{40,10},{64,14},{44,54},{5,49},{68,22},{28,35},{80,66},{45,1},
            {50,38},{42,73},{36,32},{5,10},{55,8},{10,40},{40,50},{55,28},{4,51},{18,22},
            {26,65},{33,17},{46,54},{43,59},{5,76},{14,33},{77,4},{19,5},{59,22},{21,26},
            {59,42},{6,11},{63,69},{26,45},{3,42},{21,58},{65,55},{69,70},{64,61},{76,25},
            {2,72},{43,77},{29,68},{65,33},{48,44},{35,15},{45,38},{54,73},{71,75},{28,73},
            {80,79},{74,42},{11,3},{35,13},{31,9},{80,24},{65,64},{22,69},{66,27},{70,29},
            {58,2},{39,17},{39,17},{39,17},{39,17},{39,17}
    };

    Solution sol;
    std::cout << sol.interchangeableRectangles(rectangles) << std::endl;

    return 0;
}

/* SOLUTION */

long long Solution::interchangeableRectangles(std::vector<std::vector<int>> &rectangles) {

    std::unordered_map<uint64_t, int32_t> map;
    map.reserve(1024);

    long long res = 0;
    int gcd;
    uint64_t key;
    for (int i = 0; i < rectangles.size(); ++i) {
        gcd = std::__gcd(rectangles[i][0], rectangles[i][1]);
        key = (uint64_t) (rectangles[i][0] / gcd) << 32 | rectangles[i][1] / gcd & 0xFFFFFFFFL;

        if(map.find(key) != map.end()) res += map[key];
        map[key]++;
    }
    return res;
}
