#include <cstddef>
#include <string>

class Solution {
public:
    std::string decodeString(std::string s) {
        std::string result{};

        for (size_t i{ 0 }; i < s.length(); ++i) {
            if (s.at(i) - '0' >= 0 && s.at(i) - '0' <= 9) {
                int k{ std::stoi(s.substr(i, s.find_first_of('[', i + 1) - i)) };
                size_t start{ s.find_first_of('[', i + 1) + 1 };
                int countLeft{ 0 };
                for (size_t j{ start };; ++j) {
                    if (s.at(j) == '[') {
                        ++countLeft;
                    }
                    else if (s.at(j) == ']') {
                        if (countLeft == 0) {
                            i = j;
                            break;
                        }
                        else {
                            --countLeft;
                        }
                    }
                }
                std::string processing{ decodeString(s.substr(start, i - start)) };

                for (int n{ 0 }; n < k; ++n) {
                    result += processing;
                }
            }
            else {
                result += s.at(i);
            }
        }

        return result;
    }
};
