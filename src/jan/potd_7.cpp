#include <algorithm>
#include <ranges>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
    auto stringMatching(std::vector<std::string>& words) -> std::vector<std::string> {
        std::unordered_set<std::string> res;
        for (const auto& word: words) {
            if (std::ranges::any_of(words | std::views::filter([&](const std::string& w) { return w != word; }),
                                    [&](const std::string& other) { return other.contains(word); })) {
                res.insert(word);
            }
        }

        return {res.cbegin(), res.cend()};
    }
};
