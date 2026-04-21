#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int participants{};
	int budget{};
	int hotels{};
	int weeks{};

	while (std::cin >> participants >> budget >> hotels >> weeks) {
		int minCost{ budget + 1 };
		for (int i{ 0 }; i < hotels; ++i) {
			int price{};
			std::cin >> price;
			for (int j{ 0 }; j < weeks; ++j) {
				int available{};
				std::cin >> available;

				if (participants <= available && price * participants < minCost) {
					minCost = price * participants;
				}
			}
		}

		if (minCost <= budget) {
			std::cout << minCost << '\n';
		}
		else {
			std::cout << "stay home\n";
		}
	}

	return 0;
}
