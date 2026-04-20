#include <iostream>
#include <vector>

static void solution() {
	int row{};
	int col{};
	int mid{};

	std::cin >> row >> col >> mid;
	std::cout << row << ' ' << col << ' ' << mid << '\n';

	std::vector<std::vector<char>> grid(row);
	for (int i{ 0 }; i < row; ++i) {
		for (int j{ 0 }; j < col; ++j) {
			char input{};
			std::cin >> input;
			grid[i].push_back(input);
		}
	}

	for (int k{ 0 }; k < mid; ++k) {
		int x{};
		int y{};
		std::cin >> y >> x;
		char target{ grid[y][x] };
		int radius{ 1 };

		bool searching{ true };

		while (searching) {
			if (y - radius < 0 || y + radius >= row || x - radius < 0 || x + radius >= col) {
				break;
			}

			for (int i{ x - radius }; i < x + radius; ++i) {
				if (grid[y - radius][i] != target || grid[y + radius][i] != target) {
					searching = false;
					break;
				}
			}
			for (int j{ y - radius }; j < y + radius; ++j) {
				if (grid[j][x + radius] != target || grid[j][x + radius] != target) {
					searching = false;
					break;
				}
			}

			if (searching) {
				++radius;
			}
		}

		std::cout << (radius - 1) * 2 + 1 << '\n';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int cases{};
	std::cin >> cases;

	for (int i{ 0 }; i < cases; ++i) {
		solution();
	}

	return 0;
}