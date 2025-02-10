#include <algorithm>
#include <vector>

class Solution {
public:
    int maxAscendingSum(std::vector<int>& nums) {
        auto maxSum = 0;
        auto sum = nums[0];
        for (auto i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                sum += nums[i];
            } else {
                maxSum = std::max(maxSum, sum);
                sum = nums[i];
            }
        }

        return std::max(maxSum, sum);
    }
};
