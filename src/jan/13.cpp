#include <array>
#include <string>

class Solution {
public:
    auto minimumLength(std::string s) -> int {
        if (s.size() < 3) {
            return s.size();
        }

        std::array<int, 26> freq{0};
        auto len = 0;
        for (const auto c: s) {
            ++freq[c - 'a'];
        }

        for (const auto v: freq) {
            if (v < 3) {
                len += v;
                continue;
            } else if (v % 2 != 0) {
                len += 1;
            } else if (v % 2 == 0) {
                len += 2;
            }
        }

        return len;
    }
};
