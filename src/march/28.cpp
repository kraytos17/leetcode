#include <algorithm>
#include <array>
#include <queue>
#include <vector>

namespace ranges = std::ranges;

class Solution {
public:
    std::vector<int> maxPoints(std::vector<std::vector<int>>& grid, std::vector<int>& queries) {
        const auto m = grid.size();
        const auto n = grid[0].size();
        const auto k = queries.size();

        std::vector<std::pair<int, int>> sortedQueries;
        for (int i = 0; i < k; ++i) {
            sortedQueries.emplace_back(queries[i], i);
        }
        ranges::sort(sortedQueries);

        using Cell = std::tuple<int, int, int>;
        std::vector<int> res(k, 0);
        std::priority_queue<Cell, std::vector<Cell>, std::greater<>> pq;
        std::queue<std::pair<int, int>> q;
        const std::array<std::pair<int, int>, 4> dirs = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};

        pq.emplace(grid[0][0], 0, 0);
        grid[0][0] = 0;
        int count = 0;

        for (auto it = sortedQueries.begin(); it != sortedQueries.end(); ++it) {
            auto [query, originalIdx] = *it;
            while (!pq.empty() && std::get<0>(pq.top()) < query) {
                auto [val, x, y] = pq.top();
                pq.pop();
                q.emplace(x, y);
            }

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                ++count;

                ranges::for_each(dirs, [&](const auto& dir) {
                    const auto [dx, dy] = dir;
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] != 0) {
                        if (grid[nx][ny] < query) {
                            q.emplace(nx, ny);
                        } else {
                            pq.emplace(grid[nx][ny], nx, ny);
                        }
                        grid[nx][ny] = 0;
                    }
                });
            }

            res[originalIdx] = count;

            if (count == m * n) {
                for (auto rem = it + 1; rem != sortedQueries.end(); ++rem) {
                    res[rem->second] = count;
                }
                break;
            }
        }

        return res;
    }
};
