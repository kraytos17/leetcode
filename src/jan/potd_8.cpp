#include <string>
#include <vector>

class Solution {
public:
    auto countPrefixSuffixPairs(const std::vector<std::string>& words) -> int {
        auto res = 0;
        auto n = words.size();

        for (auto i = 0uz; i < n - 1; ++i) {
            for (auto j = i + 1; j < n; ++j) {
                if (words[j].starts_with(words[i]) && words[j].ends_with(words[i])) {
                    ++res;
                }
            }
        }

        return res;
    }
};
