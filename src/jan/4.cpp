#include <bitset>
#include <print>
#include <string>

class Solution {
public:
    int countPalindromicSubsequence(std::string s) {
        std::bitset<26> leftRightPos{};
        int res = 0;
        for (auto i = 0; i < 26; ++i) {
            auto left = s.find('a' + i);
            if (left != std::string::npos) {
                auto right = s.rfind('a' + i);
                if (right - left < 2)
                    continue;

                for (auto j = left + 1; j < right; ++j) {
                    leftRightPos.set(s[j] - 'a');
                    if (leftRightPos.count() == 26)
                        break;
                }

                res += leftRightPos.count();
                leftRightPos.reset();
            }
        }

        return res;
    }
};

int main() {
    std::string s("aabca");
    Solution sol;
    auto res = sol.countPalindromicSubsequence(s);
    std::println("Result :- {}", res);

    return 0;
}
