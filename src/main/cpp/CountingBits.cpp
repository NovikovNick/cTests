#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> countBits(int n);
};

int main() {

    Solution sol;
    const std::vector<int> &res = sol.countBits(64);
    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i] << std::endl;
    }

    return 0;
}

/* SOLUTION */

std::vector<int> Solution::countBits(int n) {
    std::vector<int> res(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        res[i] = res[i / 2] + (i & 1);
    }

    return res;
}

/*int arr[] = {
        0,                                                                                              // 0
        1,                                                                                              // 1
        1,                                                                                              // 2
        2, 1,                                                                                           // 4
        2, 2, 3, 1,                                                                                     // 8
        2, 2, 3, 2, 3, 3, 4, 1,                                                                         // 16
        2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 1,                                                 // 32
        2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1  // 64
};*/
