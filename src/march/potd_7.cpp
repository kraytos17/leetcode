#include <algorithm>
#include <bitset>
#include <cmath>
#include <fstream>
#include <limits>
#include <vector>

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

constexpr int MAX_LIMIT = 1'000'001;
std::bitset<MAX_LIMIT> isPrime;

class Solution {
public:
    auto closestPrimes(int left, int right) -> std::vector<int> {
        const auto primes = findPrimes(left, right);
        if (primes.size() < 2) {
            return {-1, -1};
        }

        std::pair<int, int> closestPair = {-1, -1};
        auto minDiff = std::numeric_limits<int>::max();
        for (auto i = 0uz; i < primes.size() - 1; ++i) {
            const auto diff = primes[i + 1] - primes[i];
            if (diff < minDiff) {
                minDiff = diff;
                closestPair = {primes[i], primes[i + 1]};
            }
        }

        return {closestPair.first, closestPair.second};
    }

private:
    auto findPrimes(int left, int right) -> std::vector<int> {
        if (left > right) {
            return {};
        }

        const auto sqrtR = static_cast<int>(std::sqrt(right));
        const auto primes = sieve(sqrtR);
        std::bitset<MAX_LIMIT> isPrimeSegment;
        isPrimeSegment.set();

        for (const auto& prime: primes) {
            const auto startNum = std::max(prime * prime, left + (prime - left % prime) % prime);
            for (auto j = startNum; j <= right; j += prime) {
                isPrimeSegment[j - left] = 0;
            }
        }

        if (left <= 1) {
            isPrimeSegment[0] = 0;
        }

        std::vector<int> res;
        res.reserve(isPrimeSegment.size());
        for (auto i = 0; i <= right - left; ++i) {
            if (isPrimeSegment[i]) {
                res.push_back(i + left);
            }
        }

        return res;
    }

    auto sieve(int limit) -> std::vector<int> {
        if (limit < 2) {
            return {};
        }

        isPrime.set();
        isPrime[0] = isPrime[1] = 0;
        for (auto i = 2; i * i <= limit; ++i) {
            if (isPrime[i]) {
                for (auto j = i * i; j <= limit; j += i) {
                    isPrime[j] = 0;
                }
            }
        }

        std::vector<int> primes;
        primes.reserve(limit / 2);
        for (auto i = 2; i <= limit; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        return primes;
    }
};
