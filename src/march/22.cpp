#include <algorithm>
#include <numeric>
#include <ranges>
#include <unordered_map>
#include <utility>
#include <vector>

namespace views = std::views;
namespace ranges = std::ranges;

class Solution {
public:
    constexpr auto countCompleteComponents(int n, std::vector<std::vector<int>>& edges) -> int {
        std::vector<int> parent(n);
        std::iota(parent.begin(), parent.end(), 0);

        std::vector<int> size(n, 1);
        auto find = [&](int x) -> int {
            while (x != parent[x]) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        };

        auto unite = [&](int x, int y) -> void {
            if (auto xRoot = find(x), yRoot = find(y); xRoot != yRoot) {
                if (size[xRoot] < size[yRoot]) {
                    std::swap(xRoot, yRoot);
                }
                parent[yRoot] = xRoot;
                size[xRoot] += size[yRoot];
            }
        };

        std::unordered_map<int, int> edgeCnt;
        std::unordered_map<int, int> nodeCnt;

        for (const auto& edge: edges) {
            unite(edge[0], edge[1]);
        }
        for (const auto& i: views::iota(0, n)) {
            ++nodeCnt[find(i)];
        }
        for (const auto& edge: edges) {
            auto root = find(edge[0]);
            auto root1 = find(edge[1]);
            ++edgeCnt[root];
            ++edgeCnt[root1];
        }

        return ranges::count_if(
            nodeCnt, [&](const auto& kv) { return edgeCnt[kv.first] >> 1 == (kv.second * (kv.second - 1)) >> 1; });
    }
};
