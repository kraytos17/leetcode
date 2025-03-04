#include <vector>

class Solution {
public:
    auto xorAllNums(std::vector<int>& nums1, std::vector<int>& nums2) -> int {
        auto xor1 = 0;
        auto xor2 = 0;
        for (int num: nums1) {
            xor1 ^= num;
        }

        for (int num: nums2) {
            xor2 ^= num;
        }

        return ((nums2.size() % 2) ? xor1 : 0) ^ ((nums1.size() % 2) ? xor2 : 0);
    }
};
