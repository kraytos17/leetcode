#include <algorithm>
#include <cstdlib>
#include <deque>
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> lexicographicallySmallestArray(std::vector<int>& nums, int limit) {
        std::vector<int> numsSorted(nums);
        std::ranges::sort(numsSorted);

        std::vector<std::deque<int>> groups;
        std::unordered_map<int, int> numToGroup;
        for (int n: numsSorted) {
            if (groups.empty() || std::abs(n - groups.back().back()) > limit) {
                groups.emplace_back();
            }
            groups.back().push_back(n);
            numToGroup[n] = groups.size() - 1;
        }

        std::vector<int> res(nums.size());
        for (size_t i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            int groupIndex = numToGroup[n];
            res[i] = groups[groupIndex].front();
            groups[groupIndex].pop_front();
        }

        return res;
    }
};
