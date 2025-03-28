#include <array>
#include <string>

class Solution {
public:
    auto numberOfSubstrings(std::string s) -> int {
        const auto n = s.size();
        auto res = 0;
        std::array<int, 3> lastOcc{-1, -1, -1};
        for (auto i = 0uz; i < n; ++i) {
            const auto num = s[i] - 'a';
            lastOcc[num] = i;
            res += 1 + std::min(lastOcc[(num + 1) % 3], lastOcc[(num + 2) % 3]);
        }

        return res;
    }
};
