#include <algorithm>
#include <vector>

class Solution {
public:
    auto pivotArray(std::vector<int>& nums, int pivot) -> std::vector<int> {
        auto mid = std::ranges::stable_partition(nums, [&](auto n) { return n < pivot; });
        std::ranges::stable_partition(mid, [&](auto n) { return n == pivot; });
        return nums;
    }
};
