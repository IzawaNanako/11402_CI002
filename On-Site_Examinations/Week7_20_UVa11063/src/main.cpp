#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N{};
	int cases{ 1 };

	while (std::cin >> N) {
		std::vector<int> elements{};
		bool sum[20002]{ 0 };
		bool done{ false };
		int mem{ 0 };

		for (int i{ 0 }; i < N; ++i) {
			int input{};
			std::cin >> input;
			if (input <= mem) {
				done = true;
			}
			else {
				elements.push_back(input);
				mem = input;
			}
		}

		if (done) {
			std::cout << "Case #" << cases << ": It is not a B2-Sequence.\n\n";
			++cases;
			continue;
		}

		for (int i{ N - 1 }; i >= 0; --i) {
			for (int j{ i }; j >= 0; --j) {
				if (sum[elements.at(i) + elements.at(j)] == true) {
					done = true;
					break;
				}
				sum[elements.at(i) + elements.at(j)] = true;
			}
			if (done) {
				break;
			}
		}

		if (done) {
			std::cout << "Case #" << cases << ": It is not a B2-Sequence.\n\n";
		}
		else {
			std::cout << "Case #" << cases << ": It is a B2-Sequence.\n\n";
		}

		++cases;
	}

	return 0;
}
