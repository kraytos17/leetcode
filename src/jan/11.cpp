#include <bit>
#include <cstdint>
#include <string>

class Solution {
public:
    auto canConstruct(std::string s, int k) -> bool {
        if (s.size() < k) {
            return false;
        }

        uint32_t mask{0};
        for (const auto c: s) {
            mask ^= 1 << (c - 'a');
        }

        return std::popcount(mask) <= k;
    }
};
