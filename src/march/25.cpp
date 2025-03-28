#include <algorithm>
#include <ranges>
#include <vector>

namespace ranges = std::ranges;
namespace views = std::views;

class Solution {
public:
    constexpr auto checkValidCuts(int n, std::vector<std::vector<int>>& rectangles) -> bool {
        const auto isValid = [&](int sortIdx, int start, int end) -> bool {
            ranges::sort(rectangles, [&](const auto& a, const auto& b) { return a[sortIdx] < b[sortIdx]; });

            int currentEnd = rectangles[0][end];
            int intervals = 1;
            for (const auto& rect: views::all(rectangles) | views::drop(1)) {
                if (rect[start] < currentEnd) {
                    currentEnd = std::max(rect[end], currentEnd);
                } else {
                    ++intervals;
                    currentEnd = rect[end];
                }
            }

            return intervals > 2;
        };

        return isValid(0, 0, 2) || isValid(1, 1, 3);
    }
};
