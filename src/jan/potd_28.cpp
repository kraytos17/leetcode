#include <algorithm>
#include <vector>

class Solution {
public:
    int findMaxFish(std::vector<std::vector<int>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();
        const std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        auto res = 0;

        auto dfs = [&](int x, int y, auto&& dfsRec) -> int {
            if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] == 0) {
                return 0;
            }

            auto fishCount = grid[x][y];
            grid[x][y] = 0;

            for (auto [dx, dy]: directions) {
                fishCount += dfsRec(x + dx, y + dy, dfsRec);
            }

            return fishCount;
        };

        for (auto i = 0; i < rows; ++i) {
            for (auto j = 0; j < cols; ++j) {
                if (grid[i][j] > 0) {
                    res = std::max(res, dfs(i, j, dfs));
                }
            }
        }

        return res;
    }
};
