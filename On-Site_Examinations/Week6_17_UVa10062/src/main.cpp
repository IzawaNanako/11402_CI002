#include <iostream>
#include <string>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string input{};

	while (std::getline(std::cin, input)) {
		int count[128]{ 0 };
		for (auto c : input) {
			++count[c];
		}
		
		std::vector<int> characters{};
		std::vector<int> finalCount{};

		for (int i{ 0 }; i < 128; ++i) {
			if (count[i] > 0) {
				characters.push_back(i);
				finalCount.push_back(count[i]);
			}
		}

		for (int i{ 0 }; i < characters.size(); ++i) {
			for (int j{ 0 }; j < characters.size(); ++j) {
				if (finalCount.at(j) > finalCount.at(i)) {
					std::swap(finalCount.at(j), finalCount.at(i));
					std::swap(characters.at(j), characters.at(i));
				}
				else if (finalCount.at(j) == finalCount.at(i) && characters.at(j) < characters.at(i)) {
					std::swap(finalCount.at(j), finalCount.at(i));
					std::swap(characters.at(j), characters.at(i));
				}
			}
		}

		for (int k{ 0 }; k < characters.size(); ++k) {
			std::cout << characters.at(k) << ' ' << finalCount.at(k) << '\n';
		}

		std::cout << '\n';
	}

	return 0;
}