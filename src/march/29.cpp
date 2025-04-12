#include <algorithm>
#include <cstdint>
#include <stack>
#include <vector>

namespace ranges = std::ranges;

class Solution {
public:
    constexpr auto maximumScore(std::vector<int>& nums, int64_t k) -> int64_t {
        constexpr auto MODULO = 1'000'000'007;
        constexpr auto primeScore = [](int64_t x) -> int64_t {
            if (x < 2) {
                return 0;
            }

            int64_t count = 0;
            if (x % 2 == 0) {
                ++count;
                x >>= std::countr_zero(static_cast<uint64_t>(x));
            }
            for (int64_t i = 3; i * i <= x; i += 2) {
                if (x % i == 0) {
                    ++count;
                    do {
                        x /= i;
                    } while (x % i == 0);
                }
            }
            return count + (x > 1);
        };

        const auto n = nums.size();
        std::vector<int64_t> pScoreVec(n);
        for (auto i = 0uz; i < n; ++i) {
            pScoreVec[i] = primeScore(nums[i]);
        }

        int64_t res = 1;
        std::vector<int64_t> nextRightIdx(n, n);
        std::vector<int64_t> prevLeftIdx(n, -1);
        std::stack<int64_t> monoStack;

        for (auto i = 0uz; i < n; ++i) {
            while (!monoStack.empty() && pScoreVec[monoStack.top()] < pScoreVec[i]) {
                monoStack.pop();
            }
            if (!monoStack.empty()) {
                prevLeftIdx[i] = monoStack.top();
            }
            monoStack.push(i);
        }

        monoStack = std::stack<int64_t>();
        for (int64_t i = n - 1; i >= 0; --i) {
            while (!monoStack.empty() && pScoreVec[monoStack.top()] <= pScoreVec[i]) {
                monoStack.pop();
            }
            if (!monoStack.empty()) {
                nextRightIdx[i] = monoStack.top();
            }
            monoStack.push(i);
        }

        std::vector<std::pair<int64_t, int64_t>> elems;
        for (auto i = 0uz; i < n; ++i) {
            auto left = prevLeftIdx[i] + 1;
            auto right = nextRightIdx[i] - 1;
            int64_t cnt = (i - left + 1) * (right - i + 1);
            elems.emplace_back(nums[i], cnt);
        }

        ranges::sort(elems, [](const auto& a, const auto& b) -> bool { return a.first > b.first; });
        for (const auto& [num, cnt]: elems) {
            if (k <= 0) {
                break;
            }
            int64_t take = std::min(k, cnt);
            res = (res * modPow(num, take, MODULO)) % MODULO;
            k -= take;
        }

        return res;
    }

private:
    constexpr auto modPow(int64_t base, int64_t exp, int64_t mod) const -> int64_t {
        int64_t result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
};
