#include <algorithm>
#include <cctype>
#include <stack>
#include <string>

class Solution {
public:
    std::string clearDigits(std::string& s) {
        std::stack<char> stack;
        std::string res;
        for (auto c: s) {
            if (std::isdigit(c)) {
                if (!stack.empty()) {
                    stack.pop();
                }
            } else {
                stack.push(c);
            }
        }

        while (!stack.empty()) {
            res += stack.top();
            stack.pop();
        }
        std::reverse(res.begin(), res.end());

        return res;
    }
};

// class Solution {
// public:
//     std::string clearDigits(std::string& s) {
//         std::deque<char> dq;

//         for (char c: s) {
//             if (std::isdigit(c)) {
//                 if (!dq.empty()) {
//                     dq.pop_back();
//                 }
//             } else {
//                 dq.push_back(c);
//             }
//         }

//         return std::string(dq.begin(), dq.end());
//     }
// };
