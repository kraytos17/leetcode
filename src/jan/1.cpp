#include <limits>
#include <print>
#include <ranges>
#include <string>

class Solution {
public:
    int maxScore(std::string s) {
        int oneCount = 0;
        int zeroCount = 0;
        int diff = std::numeric_limits<int>::min();

        for (const auto& elem: std::ranges::subrange(s.cbegin(), s.cend() - 1)) {
            if (elem == '1') {
                ++oneCount;
            } else {
                ++zeroCount;
            }

            diff = std::max(diff, zeroCount - oneCount);
        }

        if (s[s.size() - 1] == '1') {
            ++oneCount;
        }

        return diff + oneCount;
    }
};

int main() {
    std::string s("11100");
    Solution sol;
    std::println("Result :- {}", sol.maxScore(s));
}
