#include <bitset>
#include <vector>

class Solution {
public:
    auto findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) -> std::vector<int> {
        std::bitset<51> seenA;
        std::bitset<51> seenB;
        std::vector<int> res(A.size(), 0);

        for (auto i = 0uz; i < A.size(); ++i) {
            auto a = A[i];
            auto b = B[i];
            seenA[a] = 1;
            seenB[b] = 1;

            res[i] = (seenA & seenB).count();
        }

        return res;
    }
};
