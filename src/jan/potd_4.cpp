#include <string>

class Solution {
public:
    int countPalindromicSubsequence(std::string s) {
        for (size_t i = 0; i < s.size(); ++i) {
            auto elem = s[i];
            if (s.find(elem) - i) {

            }
        }
    }
};
