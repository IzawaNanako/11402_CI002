#include <iostream>
#include <vector>
#include <string>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int cases{};
	std::cin >> cases;

	for (int i{ 0 }; i < cases; ++i) {
		int instructions{};
		std::cin >> instructions;

		std::vector<int> memory{};
		int location{ 0 };

		for (int j{ 0 }; j < instructions; ++j) {
			std::string input{};
			std::cin >> input;

			if (input == "LEFT") {
				memory.push_back(-1);
				--location;
			}
			else if (input == "SAME") {
				std::cin >> input;
				int num{};
				std::cin >> num;
				memory.push_back(memory.at(num - 1));
				location += memory.at(num - 1);
			}
			else {
				memory.push_back(1);
				++location;
			}
		}

		std::cout << location << '\n';
	}

	return 0;
}
