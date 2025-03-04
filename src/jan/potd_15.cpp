#include <bit>
#include <cstdint>

class Solution {
public:
    constexpr auto minimizeXor(int num1, int num2) -> int {
        auto setBits = std::popcount(static_cast<uint32_t>(num2));
        auto res = 0;

        for (auto i = 31; i >= 0 && setBits > 0; --i) {
            if (num1 & (1 << i)) {
                res |= (1 << i);
                --setBits;
            }
        }

        for (auto i = 0uz; i < 32 && setBits > 0; ++i) {
            if (!(res & (1 << i))) {
                res |= (1 << i);
                --setBits;
            }
        }

        return res;
    }
};
