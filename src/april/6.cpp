#include <algorithm>
#include <ranges>
#include <vector>

namespace ranges = std::ranges;
namespace views = std::views;

class Solution {
public:
    constexpr auto largestDivisibleSubset(std::vector<int>& nums) -> std::vector<int> {
        if (nums.empty()) {
            return {};
        }

        ranges::sort(nums);
        const auto n = nums.size();
        std::vector<int> dp(n, 1);
        std::vector<int> prev(n, -1);
        int maxIndex = 0;

        for (auto i: views::iota(1UL, n)) {
            for (auto j: views::iota(0UL, i)) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxIndex]) {
                maxIndex = i;
            }
        }

        std::vector<int> result;
        result.reserve(maxIndex);
        for (int k = maxIndex; k >= 0; k = prev[k]) {
            result.push_back(nums[k]);
            if (prev[k] == -1) {
                break;
            }
        }

        ranges::reverse(result);
        return result;
    }
};
