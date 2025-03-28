#include <algorithm>
#include <vector>

namespace ranges = std::ranges;

class Solution {
public:
    // Boyer Moore Majority Voting Algo
    constexpr auto minimumIndex(std::vector<int>& nums) noexcept -> int {
        int candidate = nums.front();
        int count = 1;
        for (auto it = nums.begin() + 1; it != nums.end(); ++it) {
            count += (*it == candidate) ? 1 : -1;
            if (count == 0) {
                candidate = *it;
                count = 1;
            }
        }

        const int majorityThreshold = nums.size() / 2 + 1;
        const int total = ranges::count(nums, candidate);
        if (total < majorityThreshold) {
            return -1;
        }

        int leftCount = 0;
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            leftCount += (nums[i] == candidate);
            const int right_count = total - leftCount;
            if (leftCount * 2 > (i + 1) && right_count * 2 > (n - i - 1)) {
                return i;
            }
        }

        return -1;
    }
};
