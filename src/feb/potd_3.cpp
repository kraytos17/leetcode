#include <algorithm>
#include <vector>

class Solution {
public:
    int longestMonotonicSubarray(std::vector<int>& nums) {
        auto maxLen = 1;
        auto incLen = 1;
        auto decLen = 1;
        for (auto i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                ++incLen;
                decLen = 1;
            } else if (nums[i] < nums[i - 1]) {
                ++decLen;
                incLen = 1;
            } else {
                incLen = decLen = 1;
            }

            maxLen = std::max(maxLen, std::max(incLen, decLen));
        }

        return maxLen;
    }
};
