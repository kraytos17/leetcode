#include <cstdlib>
#include <print>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> minOperations(std::string boxes) {
        auto n = boxes.size();
        std::vector<int> res(n, 0);

        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (boxes[j] == '1') {
                    res[i] += std::abs(i - j);
                }
            }
        }

        return res;
    }
};

int main() {
    std::string boxes("001011");
    Solution s;
    s.minOperations(boxes);
}
