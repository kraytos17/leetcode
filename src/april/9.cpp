#include <unordered_set>
#include <vector>

class Solution {
public:
    constexpr int minOperations(std::vector<int>& nums, int k) {
        std::unordered_set<int> uniqueAboveK;
        bool hasK = false;
        bool belowK = false;

        for (int num: nums) {
            if (num == k) {
                hasK = true;
            } else if (num > k) {
                uniqueAboveK.insert(num);
            } else {
                belowK = true;
            }
        }

        if (belowK) {
            return -1;
        }
        if (uniqueAboveK.empty()) {
            return 0;
        }
        return uniqueAboveK.size();
    }
};
