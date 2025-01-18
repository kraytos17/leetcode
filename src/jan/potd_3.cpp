#include <cstdint>
#include <numeric>
#include <print>
#include <vector>

class Solution {
public:
    int64_t waysToSplitArray(std::vector<int>& nums) {
        int64_t count = 0;
        int64_t total_sum = std::accumulate(nums.begin(), nums.end(), 0LL);

        int64_t left_sum = 0;
        for (size_t i = 0; i < nums.size() - 1; ++i) {
            left_sum += nums[i];
            if (left_sum >= total_sum - left_sum) {
                ++count;
            }
        }

        return count;
    }
};

int main() {
    std::vector<int> nums = {2, 3, 1, 0};
    Solution sol;
    auto res = sol.waysToSplitArray(nums);
    std::println("Result :- {}", res);

    return 0;
}
