#include <iostream>
#include <string>
#include <vector>

static void solution() {
	std::vector<std::string> sentences{};
	std::string input{};
	std::size_t maxSize{ 0 };

	while (getline(std::cin, input)) {
		if (input.length() > maxSize) {
			maxSize = input.length();
		}

		sentences.push_back(input);
	}

	for (std::size_t i{ 0 }; i < maxSize; ++i) {
		for (std::size_t j{ sentences.size() }; j-- != 0;) {
			if (i >= sentences.at(j).length()) {
				std::cout << ' ';
			}
			else {
				std::cout << sentences.at(j).at(i);
			}
		}

		std::cout << '\n';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solution();

	return 0;
}
