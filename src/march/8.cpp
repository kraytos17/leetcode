#include <algorithm>
#include <limits>
#include <span>
#include <string>

class Solution {
public:
    auto minimumRecolors(std::string blocks, int k) -> int {
        auto minChanges = std::numeric_limits<long>::max();
        for (auto i = 0uz; i + k <= blocks.size(); ++i) {
            std::span<char> window(blocks.begin() + i, k);
            auto changeChar = std::ranges::count(window, 'W');
            minChanges = std::min(minChanges, changeChar);
        }

        return minChanges;
    }
};
