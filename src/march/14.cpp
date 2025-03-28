#include <cstdint>
#include <numeric>
#include <vector>

class Solution {
public:
    auto maximumCandies(std::vector<int>& candies, int64_t k) -> int {
        if (std::accumulate(candies.begin(), candies.end(), 0) < k) {
            return 0;
        }
        
        
    }
};
