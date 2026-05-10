#include <iostream>
#include <string>
#include <stack>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string input{};
	std::getline(std::cin, input);
	int lines{ std::stoi(input) };
	while (lines > 0) {
		std::getline(std::cin, input);
		std::stack<char> memory{};
		bool failed{ false };
		memory.push('!');

		for (auto c : input) {
			if (c == '(') {
				memory.push(')');
			}
			else if (c == '[') {
				memory.push(']');
			}
			else if (c == memory.top()) {
				memory.pop();
			}
			else {
				failed = true;
				break;
			}
		}

		if (memory.top() != '!' || failed) {
			std::cout << "No\n";
		}
		else {
			std::cout << "Yes\n";
		}

		--lines;
	}

	return 0;
}
