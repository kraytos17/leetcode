#include <algorithm>
#include <cstdint>
#include <ranges>
#include <vector>

namespace views = std::views;

class Solution {
public:
    constexpr auto maximumTripletValue(std::vector<int>& nums) -> int64_t {
        int64_t ans = 0;
        int64_t maxL = 0;
        int64_t maxDiff = 0;
        const int64_t n = nums.size();
        if (n < 3) {
            return 0;
        }

        for (const auto i: views::iota(1LL, n - 1)) {
            maxL = std::max(maxL, static_cast<int64_t>(nums[i - 1]));
            maxDiff = std::max(maxDiff, maxL - nums[i]);
            ans = std::max(ans, maxDiff * nums[i + 1]);
        }
        return ans;
    }
};
