#include <vector>

class Solution {
public:
    constexpr auto subsetXORSum(std::vector<int>& nums) -> int {
        int total = 0;
        for (const int num: nums) {
            total |= num;
        }
        return total * (1 << (nums.size() - 1));
    }
};
