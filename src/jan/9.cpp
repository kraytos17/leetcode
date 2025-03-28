#include <string>
#include <vector>

class Solution {
public:
    auto prefixCount(std::vector<std::string>& words, std::string pref) -> int {
        auto count = 0;
        for (const auto& word: words) {
            if (word.find(pref) == 0) {
                ++count;
            }
        }

        return count;
    }
};
