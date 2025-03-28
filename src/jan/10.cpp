#include <array>
#include <cstdint>
#include <string>
#include <vector>

class Solution {
public:
    auto wordSubsets(std::vector<std::string>& words1, std::vector<std::string>& words2) -> std::vector<std::string> {
        std::array<uint8_t, 26> maxFreq{};
        for (const auto& elem: words2) {
            std::array<uint8_t, 26> tempFreq{};
            for (auto c: elem) {
                ++tempFreq[c - 'a'];
            }

            for (auto i = 0uz; i < 26; ++i) {
                maxFreq[i] = std::max(maxFreq[i], tempFreq[i]);
            }
        }

        std::vector<std::string> res;
        res.reserve(words1.size());

        for (const auto& elem: words1) {
            std::array<uint8_t, 26> wordFreq{};
            for (auto c: elem) {
                ++wordFreq[c - 'a'];
            }

            bool isUniversalWord = true;
            for (auto i = 0uz; i < 26; ++i) {
                if (wordFreq[i] < maxFreq[i]) {
                    isUniversalWord = false;
                    break;
                }
            }

            if (isUniversalWord) {
                res.push_back(elem);
            }
        }

        return res;
    }
};
