#include <bitset>
#include <numeric>
#include <vector>

class Solution {
public:
    constexpr auto canPartition(const std::vector<int>& nums) -> bool {
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        if (total & 1) {
            return false;
        }

        const int target = total / 2;
        std::bitset<10001> dp;
        dp[0] = 1;

        for (const int num: nums) {
            dp |= (dp << num);
        }

        return dp[target];
    }
};
