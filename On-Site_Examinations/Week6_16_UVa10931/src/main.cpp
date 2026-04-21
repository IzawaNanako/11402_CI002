#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int input{};

	while (std::cin >> input && input != 0) {
		std::vector<int> binary{};
		int count{ 0 };
		while (input > 0) {
			if (input % 2 == 0) {
				binary.push_back(0);
			}
			else {
				binary.push_back(1);
				++count;
			}

			input /= 2;
		}

		std::cout << "The parity of ";
		for (auto v{ binary.rbegin() }; v != binary.rend(); ++v) {
			std::cout << *v;
		}
		std::cout << " is " << count << " (mod 2).\n";
	}

	return 0;
}
