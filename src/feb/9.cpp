#include <cstdint>
#include <unordered_map>
#include <vector>

class Solution {
public:
    // !(i < j && nums[j] - nums[i] != j - i)
    // i >= j || nums[j] - j == nums[i] - i
    int64_t countBadPairs(std::vector<int>& nums) {
        std::unordered_map<int, int> good;
        good.reserve(nums.size());
        int64_t goodPair = 0;
        int64_t n = nums.size();
        for (auto i = 0; i < n; ++i) {
            auto diff = nums[i] - i;
            goodPair += good[diff]++;
        }
        return (n * (n - 1) >> 1) - goodPair;
    };
};
