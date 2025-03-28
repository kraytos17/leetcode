#include <string>
#include <vector>

class Solution {
public:
    std::string shiftingLetters(std::string& s, std::vector<std::vector<int>>& shifts) {
        auto n = s.size();
        std::vector<int> shiftVec(n + 1, 0);
        for (const auto& shift: shifts) {
            auto left = shift[0];
            auto right = shift[1];
            auto dir = shift[2];
            auto val = dir == 1 ? 1 : -1;

            shiftVec[left] += val;
            shiftVec[right + 1] -= val;
        }

        auto cumulativeShift = 0;
        for (auto i = 0; i < n; ++i) {
            cumulativeShift += shiftVec[i];
            auto netShift = cumulativeShift % 26;
            s[i] = (s[i] - 'a' + netShift + 26) % 26 + 'a';
        }

        return s;
    }
};
