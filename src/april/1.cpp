#include <cstdint>
#include <sys/types.h>
#include <vector>

class Solution {
public:
    constexpr auto mostPoints(std::vector<std::vector<int>>& questions) -> int64_t {
        const auto n = questions.size();
        std::vector<int64_t> cache(n + 1, 0);
        for (ssize_t i = n - 1; i >= 0; --i) {
            auto pts = questions[i][0];
            auto brainpw = questions[i][1];
            auto chooseQ = pts + (i + 1 + brainpw < n ? cache[i + 1 + brainpw] : 0);
            auto skip = cache[i + 1];
            cache[i] = std::max(chooseQ, skip);
        }
        return cache[0];
    }
};
