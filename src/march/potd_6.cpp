#include <cstdint>
#include <vector>

class Solution {
public:
    auto findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid) -> std::vector<int> {
        int64_t n = grid.size();
        int64_t total = n * n;
        int64_t S = total * (total + 1) / 2;
        int64_t S2 = total * (total + 1) * (2 * total + 1) / 6;
        int64_t actualSum = 0;
        int64_t actualSumSquares = 0;
        for (const auto& row: grid) {
            for (int num: row) {
                actualSum += num;
                actualSumSquares += num * num;
            }
        }

        int64_t diffSum = actualSum - S;
        int64_t diffSquares = actualSumSquares - S2;
        int64_t sumRM = diffSquares / diffSum;

        int r = (diffSum + sumRM) / 2;
        int m = sumRM - r;

        return {r, m};
    }
};
