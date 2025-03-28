#include <vector>

class Solution {
public:
    auto doesValidArrayExist(std::vector<int>& derived) -> bool {
        auto ans = 0;
        for (const auto i: derived) {
            ans ^= i;
        }

        return ans == 0 ? true : false;
    }
};
