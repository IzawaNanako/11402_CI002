#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int lines{};
    std::cin >> lines;

    int result[26]{ 0 };

    char input{};
    while (std::cin >> input) {
        if (input >= 'A' && input <= 'Z') {
            ++result[input - 'A'];
        }
        else if (input >= 'a' && input <= 'z') {
            ++result[input - 'a'];
        }
    }

    std::vector<int> size{};
    for (int i{ 0 }; i < 26; ++i) {
        if (result[i] > 0) {
            size.push_back(result[i]);
        }
    }
    std::sort(size.rbegin(), size.rend());
    std::vector<std::set<char>> output(size.size());
    bool seen[26]{ false };
    for (int k{ 0 }; k < size.size(); ++k) {
        for (int i{ 0 }; i < 26; ++i) {
            if (result[i] == size.at(k) && !seen[i]) {
                seen[i] = true;
                output.at(k).insert(i + 'A');
            }
        }
    }

    for (int i{ 0 }; i < output.size(); ++i) {
        for (auto v : output.at(i)) {
            std::cout << v << ' ' << result[v - 'A'] << '\n';
        }
    }

    return 0;
}
