#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int cases{ 1 };
	int marbles{};
	int queries{};
	while (std::cin >> marbles >> queries && !(marbles == 0 && queries == 0)) {
		std::cout << "CASE #" << cases << ":\n";

		std::vector<int> storage{};

		for (int i{ 0 }; i < marbles; ++i) {
			int input{};
			std::cin >> input;
			storage.push_back(input);
		}

		std::sort(storage.begin(), storage.end());

		for (int i{ 0 }; i < queries; ++i) {
			int finding{};
			std::cin >> finding;

			auto found = std::lower_bound(storage.begin(), storage.end(), finding);

			if (found != storage.end() && *found == finding) {
				std::cout << finding << " found at " << std::distance(storage.begin(), found) + 1 << '\n';
			}
			else {
				std::cout << finding << " not found\n";
			}
		}

		++cases;
	}

	return 0;
}
