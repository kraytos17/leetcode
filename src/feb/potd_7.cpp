#include <ios>
#include <iostream>
#include <unordered_map>
#include <vector>

static auto init = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    std::vector<int> queryResults(int limit, std::vector<std::vector<int>>& queries) {
        std::unordered_map<int, int> balls;
        std::unordered_map<int, int> colorFreq;
        auto uniqueColors = 0;
        std::vector<int> res;
        res.reserve(queries.size());

        for (const auto& query: queries) {
            auto pos = query[0];
            auto color = query[1];
            auto prevColor = balls.contains(pos) ? balls[pos] : -1;

            if (prevColor != -1) {
                if (--colorFreq[prevColor] == 0) {
                    colorFreq.erase(prevColor);
                    --uniqueColors;
                }
            }

            balls[pos] = color;
            if (++colorFreq[color] == 1) {
                ++uniqueColors;
            }

            res.push_back(uniqueColors);
        }

        return res;
    }
};
