#include <algorithm>
#include <ranges>
#include <vector>

namespace ranges = std::ranges;

class Solution {
public:
    constexpr auto minOperations(std::vector<std::vector<int>>& grid, int x) -> int {
        const int remainder = grid[0][0] % x;
        const auto rows = grid.size();
        const auto cols = grid[0].size();
        const auto totalSize = rows * cols;

        std::vector<int> flattened;
        flattened.reserve(totalSize);
        for (const auto& row: grid) {
            for (const int num: row) {
                if (num % x != remainder)
                    return -1;
                flattened.push_back(num);
            }
        }

        const auto mid = flattened.begin() + totalSize / 2;
        ranges::nth_element(flattened, mid);
        const int median = *mid;
        int total = 0;
        for (int num: flattened) {
            int diff = num - median;
            diff = (diff < 0) ? -diff : diff;
            total += diff / x;
        }

        return total;
    }
};
