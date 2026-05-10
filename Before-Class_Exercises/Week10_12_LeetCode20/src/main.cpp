#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> memory{};
        memory.push('!')
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                if (c == '(') {
                    memory.push(')');
                }
                else if (c == '[') {
                    memory.push(']');
                }
                else {
                    memory.push('}');
                }
            }
            else {
                if (c == memory.at(memory.top()) {
                    memory.pop();
                }
                else {
                    return false;
                }
            }
        }

        if (memory.size() != 1) {
            return false;
        }

        return true;
    }
};
