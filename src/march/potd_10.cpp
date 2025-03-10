#include <array>
#include <bitset>
#include <string>

class Solution {
public:
    constexpr auto countOfSubstrings(std::string word, int k) -> int64_t {
        constexpr std::array<char, 5> vowels{'a', 'e', 'i', 'o', 'u'};
        constexpr auto vowelIndex = [] {
            std::array<int, 128> arr{};
            arr['a'] = 0;
            arr['e'] = 1;
            arr['i'] = 2;
            arr['o'] = 3;
            arr['u'] = 4;
            return arr;
        }();

        std::array<int, 128> vowelFrequency{};
        std::bitset<5> uniqueVowels;
        int consonants = 0;
        int64_t response = 0;
        size_t left = 0;
        int extraLeft = 0;

        for (size_t right = 0; right < word.size(); ++right) {
            const char currentChar = word[right];
            bool isVowel = false;
            for (char v: vowels) {
                if (currentChar == v) {
                    isVowel = true;
                    break;
                }
            }

            if (isVowel) {
                if (++vowelFrequency[currentChar] == 1) {
                    uniqueVowels.set(vowelIndex[currentChar]);
                }
            } else {
                ++consonants;
            }

            while (consonants > k) {
                const char leftChar = word[left++];
                bool isLeftVowel = false;
                for (char v: vowels) {
                    if (leftChar == v) {
                        isLeftVowel = true;
                        break;
                    }
                }
                if (isLeftVowel) {
                    if (--vowelFrequency[leftChar] == 0) {
                        uniqueVowels.reset(vowelIndex[leftChar]);
                    }
                } else {
                    --consonants;
                }
                extraLeft = 0;
            }

            bool isLeftCharVowel = false;
            for (char v: vowels) {
                if (word[left] == v) {
                    isLeftCharVowel = true;
                    break;
                }
            }

            while (uniqueVowels.count() == 5 && consonants == k && isLeftCharVowel && vowelFrequency[word[left]] > 1) {
                ++extraLeft;
                --vowelFrequency[word[left++]];
            }

            if (uniqueVowels.count() == 5 && consonants == k) {
                response += (1 + extraLeft);
            }
        }

        return response;
    }
};
