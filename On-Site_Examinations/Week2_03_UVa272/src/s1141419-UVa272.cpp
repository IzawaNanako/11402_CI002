#include <iostream>

static void solution() {
	char input{ getchar() };
	bool opening{ true };
	while (input != EOF) {
		if (input == '"' && opening) {
			std::cout << "``";

			opening = false;
		}
		else if (input == '"') {
			std::cout << "''";

			opening = true;
		}
		else {
			std::cout << input;
		}

		input = getchar();
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solution();

	return 0;
}
