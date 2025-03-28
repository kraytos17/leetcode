#include <vector>

class Solution {
public:
    bool check(std::vector<int>& nums) {
        auto count = 0;
        for (auto i = 0; i < nums.size(); ++i) {
            if (nums[i] > nums[(i + 1) % nums.size()]) {
                ++count;
            }
        }

        return count <= 1;
    }
};
