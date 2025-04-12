#include <vector>

class Solution {
public:
    constexpr auto minimumOperations(std::vector<int>& nums) -> int {
        std::vector<int> minOps(101);
        for (auto i = std::ssize(nums) - 1; i >= 0; --i) {
            if (++minOps[nums[i]] > 1) {
                return (i + 3) / 3;
            }
        }
        return 0;
    }
};
