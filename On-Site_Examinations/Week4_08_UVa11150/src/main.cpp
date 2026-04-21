#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int bottles{};

	while (std::cin >> bottles) {
		int enojoyed{ bottles };

		while (bottles > 1) {
			enojoyed += bottles / 3;
			bottles = bottles / 3 + bottles % 3;

			if (bottles == 2) {
				++enojoyed;
				bottles = 0;
			}
		}

		std::cout << enojoyed << '\n';
	}

	return 0;
}
