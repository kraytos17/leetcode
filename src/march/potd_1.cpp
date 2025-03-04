#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> applyOperations(std::vector<int>& nums) {
        for (auto i = 0uz; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        auto it = std::ranges::remove(nums, 0).begin();
        std::fill(it, nums.end(), 0);

        return nums;
    }
};
