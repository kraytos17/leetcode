#include <cmath>
#include <vector>

class Solution {
public:
    auto maximumCount(std::vector<int>& nums) -> int {
        auto neg = 0;
        auto pos = 0;
        for (const auto& num: nums) {
            if (num == 0) {
                continue;
            }

            if (std::signbit(num)) {
                ++neg;
            } else {
                ++pos;
            }
        }

        return std::max(neg, pos);
    }
};
