#include <cstddef>
#include <iostream>
#include <vector>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int leftSum{ 0 };
        int rightSum{ 0 };

        for (size_t i{ 1 }; i < nums.size(); ++i) {
            rightSum += nums.at(i);
        }

        if (rightSum == 0) {
            return 0;
        }

        for (size_t i{ 1 }; i < nums.size(); ++i) {
            leftSum += nums.at(i - 1);
            rightSum -= nums.at(i);

            if (leftSum == rightSum) {
                return i;
            }
        }

        return -1;
    }
};
