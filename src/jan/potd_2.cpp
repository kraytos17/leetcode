#include <cstddef>
#include <print>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> vowelStrings(std::vector<std::string>& words, std::vector<std::vector<int>>& queries) {
        std::vector<int> res;
        res.reserve(queries.size());

        std::vector<int> prefixSum(words.size() + 1, 0);
        auto isVowel = [](char ch) -> bool { return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'; };
        for (size_t i = 0; i < words.size(); ++i) {
            if (isVowel(words[i].front()) && isVowel(words[i].back())) {
                prefixSum[i + 1] = prefixSum[i] + 1;
            } else {
                prefixSum[i + 1] = prefixSum[i];
            }
        }

        for (const auto& query: queries) {
            auto l = query[0];
            auto r = query[1];
            res.push_back(prefixSum[r + 1] - prefixSum[l]);
        }

        return res;
    }
};

int main() {
    std::vector<std::string> words = {"a", "e", "i"};
    std::vector<std::vector<int>> queries = {{0, 2}, {0, 1}, {2, 2}};

    Solution sol;
    auto res = sol.vowelStrings(words, queries);
    std::println("Result :-");
    for (const auto& e: res) {
        std::println("{}", e);
    }

    return 0;
}
