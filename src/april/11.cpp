#include <numeric>
#include <ranges>
#include <string>

namespace views = std::views;

class Solution {
public:
    constexpr int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (auto i: views::iota(low, high + 1)) {
            std::string str = std::to_string(i);
            const auto len = str.length();
            if (!(len & 1)) {
                auto n = len / 2;
                auto firstN = str | views::take(n) | views::transform([](char c) { return c - '0'; });
                auto lastN = str | views::drop(n) | views::transform([](char c) { return c - '0'; });

                int firstSum = std::accumulate(firstN.begin(), firstN.end(), 0);
                int lastSum = std::accumulate(lastN.begin(), lastN.end(), 0);
                if (firstSum == lastSum) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
