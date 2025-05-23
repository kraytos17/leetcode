#include <unordered_map>
#include <vector>

class Solution {
public:
    int firstCompleteIndex(std::vector<int>& arr, std::vector<std::vector<int>>& mat) {
        auto rows = mat.size();
        auto cols = mat[0].size();

        std::unordered_map<int, std::pair<int, int>> valueToPosition;
        for (auto r = 0; r < rows; ++r) {
            for (auto c = 0; c < cols; ++c) {
                valueToPosition[mat[r][c]] = {r, c};
            }
        }

        std::vector<int> rowCount(rows, 0);
        std::vector<int> colCount(cols, 0);
        for (auto i = 0; i < arr.size(); ++i) {
            auto [r, c] = valueToPosition[arr[i]];

            if (++rowCount[r] == cols) {
                return i;
            }
            if (++colCount[c] == rows) {
                return i;
            }
        }

        return -1;
    }
};
