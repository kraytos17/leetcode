#include <vector>

class Solution {
public:
    bool isArraySpecial(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }

        for (auto i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] % 2 == nums[i + 1] % 2) {
                return false;
            }
        }

        return true;
    }
};
