#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int maximumSum(std::vector<int>& nums) {
        auto res = -1;
        std::unordered_map<int, std::pair<int, int>> sumMap;
        sumMap.reserve(nums.size());

        for (auto num: nums) {
            auto sum = digitSum(num);
            auto& [max1, max2] = sumMap[sum];
            if (num > max1) {
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max2 = num;
            }
        }

        for (const auto& [_, val]: sumMap) {
            if (val.second > 0) {
                res = std::max(res, val.first + val.second);
            }
        }

        return res;
    }

private:
    int digitSum(int num) {
        auto sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
