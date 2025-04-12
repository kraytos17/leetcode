#include <algorithm>
#include <numeric>
#include <vector>

namespace ranges = std::ranges;

class Solution {
public:
    constexpr auto putMarbles(std::vector<int>& weights, int k) -> int64_t {
        const auto n = weights.size();
        if (n == 1) {
            return 0;
        }

        std::vector<int> splitCosts;
        splitCosts.reserve(n - 1);
        for (auto i = 0uz; i < n - 1; ++i) {
            splitCosts.push_back(weights[i] + weights[i + 1]);
        }

        ranges::nth_element(splitCosts, splitCosts.begin() + k - 1);
        int64_t minSum = std::accumulate(splitCosts.begin(), splitCosts.begin() + k - 1, 0LL);
        ranges::nth_element(splitCosts, splitCosts.end() - (k - 1));
        int64_t maxSum = std::accumulate(splitCosts.end() - (k - 1), splitCosts.end(), 0LL);

        return maxSum - minSum;
    }
};
