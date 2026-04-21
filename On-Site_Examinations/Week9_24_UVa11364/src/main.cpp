#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int cases{};
	std::cin >> cases;

	for (int i{ 0 }; i < cases; ++i) {
		int stores{};
		std::cin >> stores;

		int minStore{ 100 };
		int maxStore{ -1 };

		for (int j{ 0 }; j < stores; ++j) {
			int input{};
			std::cin >> input;
			
			if (input > maxStore) {
				maxStore = input;
			}
			if (input < minStore) {
				minStore = input;
			}
		}

		std::cout << (maxStore - minStore) * 2 << '\n';
	}

	return 0;
}
