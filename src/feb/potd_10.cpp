#include <cctype>
#include <deque>
#include <string>

class Solution {
public:
    auto clearDigits(std::string& s) -> std::string {
        std::deque<char> dq;

        for (auto c: s) {
            if (std::isdigit(c)) {
                if (!dq.empty()) {
                    dq.pop_back();
                }
            } else {
                dq.push_back(c);
            }
        }

        return std::string(dq.begin(), dq.end());
    }
};

// class Solution {
// public:
//     std::string clearDigits(std::string& s) {
//         std::stack<char> stack;
//         std::string res;
//         for (auto c: s) {
//             if (std::isdigit(c)) {
//                 if (!stack.empty()) {
//                     stack.pop();
//                 }
//             } else {
//                 stack.push(c);
//             }
//         }

//         while (!stack.empty()) {
//             res += stack.top();
//             stack.pop();
//         }
//         std::reverse(res.begin(), res.end());

//         return res;
//     }
// };
