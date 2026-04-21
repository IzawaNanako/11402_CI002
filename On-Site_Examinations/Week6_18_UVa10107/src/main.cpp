#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int input{};
	std::vector<int> nums{};

	while (std::cin >> input) {
		nums.push_back(input);
		std::sort(nums.begin(), nums.end());
		if (nums.size() % 2 == 1) {
			std::cout << nums.at(nums.size() / 2);
		}
		else {
			std::cout << (nums.at(nums.size() / 2) + nums.at(nums.size() / 2 - 1)) / 2;
		}

		std::cout << '\n';
	}

	return 0;
}
