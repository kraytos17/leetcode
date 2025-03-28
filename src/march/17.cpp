#include <vector>

class Solution {
public:
    auto divideArray(std::vector<int>& nums) -> bool {
        const auto n = nums.size();
        if (n & 1) {
            return false;
        }

        const auto cap = n + 1;
        std::vector<int> freq(cap);
        for (auto i = 0uz; i < cap; ++i) {
            
        }
    }
};
