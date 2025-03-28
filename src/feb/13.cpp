#include <cstdint>
#include <queue>
#include <vector>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> pq(nums.begin(), nums.end());
        
        auto opCount = 0;
        while (pq.size() > 1 && pq.top() < k) {
            auto x = pq.top();
            pq.pop();
            auto y = pq.top();
            pq.pop();

            auto newNum = std::max(x, y) + 2 * std::min(x, y);
            pq.push(newNum);
            ++opCount;
        }

        return opCount;
    }
};
