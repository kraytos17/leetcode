#include <string>

class Solution {
public:
    auto canBeValid(std::string& s, std::string locked) -> bool {

        if (s.size() == 1 || s.size() % 2 != 0) {
            return false;
        }

        auto x = 0;

        for (auto i = 0uz; i < s.size(); ++i) {
            
        }
    }
};
