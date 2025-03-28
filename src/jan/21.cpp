#include <cstdint>
#include <limits>
#include <vector>

class Solution {
public:
    int64_t gridGame(std::vector<std::vector<int>>& grid) {
        auto len = grid[0].size();
        auto res = std::numeric_limits<int64_t>::max();
        
        std::vector<int> firstRowPrefixSum(len, 0);
        std::vector<int> secondRowPrefixSum(len, 0);
        for (size_t i = 0; i < len; ++i) {
            firstRowPrefixSum[i] = grid[0][i] + (i > 0 ? firstRowPrefixSum[i - 1] : 0);
        }
        for (size_t i = 0; i < len; ++i) {
            secondRowPrefixSum[i] = grid[1][i] + (i > 0 ? secondRowPrefixSum[i - 1] : 0);
        }
        for (size_t i = 0; i < len; ++i) {
            int64_t topLeft = firstRowPrefixSum[len - 1] - firstRowPrefixSum[i];
            int64_t bottomLeft = (i > 0 ? secondRowPrefixSum[i - 1] : 0);
            int64_t robot2 = std::max(topLeft, bottomLeft);

            res = std::min(res, robot2);
        }

        return res;
    }
};
