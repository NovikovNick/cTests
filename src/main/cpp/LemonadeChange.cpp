#include <iostream>
#include <vector>

class Solution {
public:
    bool lemonadeChange(std::vector<int> &bills);
};


int main() {

    Solution sol;
    std::vector<int> bills = {5,5,5,10,5,5,10,20,20,20};
    std::cout << sol.lemonadeChange(bills);
    return 0;
}



bool Solution::lemonadeChange(std::vector<int> &bills) {

    int16_t fives = 0;
    int16_t tenth = 0;

    for (int i = 0; i < bills.size(); ++i) {
        switch (bills[i]) {
            case 5: {
                fives++;
                break;
            }
            case 10: {
                if (fives > 0) {
                    fives--;
                    tenth++;
                    break;
                }
                return false;
            }
            case 20: {
                if (fives > 0 && tenth> 0) {
                    fives--;
                    tenth--;
                    break;
                } else if (fives >= 3) {
                    fives -= 3;
                    break;
                }
                return false;
            }
        }
    }
    return true;
}

/* SOLUTION */
