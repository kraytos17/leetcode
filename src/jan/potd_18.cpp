#include <limits>
#include <print>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

class Solution {
public:
    int minCost(std::vector<std::vector<int>>& grid) {
        auto m = grid.size();
        auto n = grid[0].size();

        // Directions matched to grid values:
        // 1 -> right (0,1)
        // 2 -> left  (0,-1)
        // 3 -> down  (1,0)
        // 4 -> up    (-1,0)
        std::vector<std::pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<>> pq;
        std::vector<std::vector<int>> cost(m, std::vector<int>(n, std::numeric_limits<int>::max()));

        cost[0][0] = 0;
        while (!pq.empty()) {
            auto [currCost, i, j] = pq.top();
            pq.pop();

            if (i == m - 1 && j == n - 1) {
                return currCost;
            }

            if (currCost > cost[i][j]) {
                continue;
            }

            for (auto d = 0uz; d < 4; ++d) {
                auto ni = i + dirs[d].first;
                auto nj = j + dirs[d].second;

                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    auto newCost = currCost + (grid[i][j] == d + 1 ? 0 : 1);
                    if (newCost < cost[ni][nj]) {
                        cost[ni][nj] = newCost;
                        pq.emplace(newCost, ni, nj);
                    }
                }
            }
        }

        return -1;
    }
};
