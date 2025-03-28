#include <vector>

class Solution {
public:
    auto minOperations(std::vector<int>& nums) -> int {
        int res = 0;
        auto n = nums.size();
        if (n < 3) {
            return (nums == std::vector<int>(n, 1)) ? 0 : -1;
        }

        for (int left = 0; left <= n - 3; ++left) {
            if (nums[left] == 0) {
                nums[left] ^= 1;
                nums[left + 1] ^= 1;
                nums[left + 2] ^= 1;
                ++res;
            }
        }

        if (nums[n - 2] == 1 && nums[n - 1] == 1) {
            return res;
        } else {
            return -1;
        }
    }
};
