#include <algorithm>
#include <array>
#include <cstdint>
#include <map>
#include <ranges>
#include <set>

namespace views = std::views;
namespace ranges = std::ranges;

class Solution {
public:
    constexpr int64_t countGoodIntegers(int n, int k) {
        std::set<std::map<int, int>> uniqueFreqs;
        int64_t ans = 0;

        std::array<int64_t, 20> fact;
        fact[0] = 1;
        for (int i: views::iota(1, 20)) {
            fact[i] = fact[i - 1] * i;
        }

        auto countPerms = [&fact](const std::map<int, int>& freq) -> int64_t {
            int tot =
                // clang-format off
                ranges::fold_left(freq, 0, [](int sum, const auto& p) { return sum + p.second; });
            // clang-format on

            int64_t denom =
                ranges::fold_left(freq, 1LL, [&fact](int64_t prod, const auto& p) { return prod * fact[p.second]; });

            return fact[tot] / denom;
        };

        auto validPermuts = [&countPerms](const std::map<int, int>& freq) -> int64_t {
            int64_t totalPerms = countPerms(freq);
            if (auto it = freq.find(0); it == freq.end() || it->second == 0) {
                return totalPerms;
            }

            std::map<int, int> freq_copy = freq;
            if (--freq_copy[0] == 0) {
                freq_copy.erase(0);
            }
            return totalPerms - countPerms(freq_copy);
        };

        const int half = (n + 1) / 2;
        std::array<int, 20> palindrome{};
        auto genPalindrome = [&](int pos, auto&& self) -> void {
            if (pos == half) {
                for (int i: views::iota(0, n - half)) {
                    palindrome[n - 1 - i] = palindrome[i];
                }

                if (palindrome[0] == 0) {
                    return;
                }

                int64_t val =
                    ranges::fold_left(views::take(palindrome, n), 0LL, [](int64_t sum, int d) { return sum * 10 + d; });

                if (val % k == 0) {
                    std::map<int, int> freq;
                    for (int d: views::take(palindrome, n)) {
                        freq[d]++;
                    }
                    uniqueFreqs.insert(std::move(freq));
                }
                return;
            }

            for (int d: views::iota(0, 10)) {
                if (pos == 0 && d == 0) {
                    continue;
                }

                palindrome[pos] = d;
                self(pos + 1, self);
            }
        };

        genPalindrome(0, genPalindrome);
        for (const auto& freq: uniqueFreqs) {
            ans += validPermuts(freq);
        }

        return ans;
    }
};
