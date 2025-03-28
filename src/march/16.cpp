#include <algorithm>
#include <cmath>
#include <cstdint>
#include <execution>
#include <numeric>
#include <vector>

class Solution {
public:
    auto repairCars(std::vector<int>& ranks, int64_t cars) -> int64_t {
        int maxRank = *std::max_element(ranks.begin(), ranks.end());
        int64_t low = 1;
        int64_t hi = static_cast<int64_t>(maxRank) * cars * cars;

        while (low < hi) {
            int64_t mid = low + (hi - low) / 2;
            int64_t repaired =
                std::transform_reduce(std::execution::par, ranks.begin(), ranks.end(), int64_t{0}, std::plus<>(),
                                      [mid](int rank) { return static_cast<int64_t>(std::sqrt(mid / rank)); });

            if (repaired < cars) {
                low = mid + 1;
            } else {
                hi = mid;
            }
        }

        return low;
    }
};
