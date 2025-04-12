#include <algorithm>
#include <array>
#include <string>
#include <vector>

class Solution {
public:
    constexpr auto partitionLabels(std::string s) const noexcept -> std::vector<int> {
        std::array<int, 26> lastOccurrence{};
        lastOccurrence.fill(-1);

        const auto size = s.size();
        for (size_t idx = 0; idx < size; ++idx) {
            lastOccurrence[s[idx] - 'a'] = static_cast<int>(idx);
        }

        int start = 0;
        int end = 0;
        std::vector<int> result;
        result.reserve(size);

        for (size_t idx = 0; idx < size; ++idx) {
            end = std::max(end, lastOccurrence[s[idx] - 'a']);
            if (static_cast<int>(idx) == end) {
                result.push_back(end - start + 1);
                start = end + 1;
            }
        }

        return result;
    }
};
