#include <vector>

class Solution {
public:
    auto numberOfAlternatingGroups(std::vector<int>& colors, int k) -> int {
        auto n = colors.size();
        auto res = 0;
        auto currAltLen = 1;
        auto prevColor = colors[0];

        for (auto i = 1uz; i < n + k - 1; ++i) {
            if (prevColor == colors[i % n]) {
                currAltLen = 1;
            } else {
                ++currAltLen;
                if (currAltLen == k) {
                    ++res;
                }
            }

            prevColor = colors[i % n]; //advance ahead
        }

        return res;
    }
};
