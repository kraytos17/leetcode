#include <cstdint>

class Solution {
public:
    auto coloredCells(int64_t n) -> int64_t { return 2 * n * (n - 1) + 1; }
};
