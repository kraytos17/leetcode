#include <flat_map>
#include <vector>

class Solution {
public:
    auto mergeArrays(std::vector<std::vector<int>>& nums1, std::vector<std::vector<int>>& nums2)
        -> std::vector<std::vector<int>> {
        std::flat_map<int, int> map;

        for (const auto& nums: {nums1, nums2}) {
            for (const auto& elem: nums) {
                map[elem[0]] += elem[1];
            }
        }

        std::vector<std::vector<int>> res;
        res.reserve(map.size());

        for (const auto& [k, v]: map) {
            res.emplace_back(std::vector<int>{k, v});
        }

        return res;
    }
};
