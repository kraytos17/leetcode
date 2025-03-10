#include <vector>

class Solution {
public:
    auto countServers(std::vector<std::vector<int>>& grid) -> int {
        const auto m = grid.size();
        const auto n = grid[0].size();
        auto total = 0;
        auto isolated = 0;

        std::vector<int> rowCount(m, 0);
        std::vector<int> colCount(n, 0);

        for (auto i = 0uz; i < m; ++i) {
            for (auto j = 0uz; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++rowCount[i];
                    ++colCount[j];
                    ++total;
                }
            }
        }

        for (auto i = 0uz; i < m; ++i) {
            for (auto j = 0uz; j < n; ++j) {
                if (grid[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1) {
                    ++isolated;
                }
            }
        }

        return total - isolated;
    }
};
