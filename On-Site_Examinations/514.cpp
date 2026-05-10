#include <iostream>
#include <vector>
#include <stack>
#include <queue>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int trainCount{};
	while (std::cin >> trainCount && trainCount != 0) {
		int input{};
		while (std::cin >> input && input != 0) {
			std::queue<int> trains{};
			for (int i{ 0 }; i < trainCount; ++i) {
				trains.push(i + 1);
			}

			std::vector<int> wanted{};
			size_t checking{ 0 };

			wanted.push_back(input);
			for (int i{ 1 }; i < trainCount; ++i) {
				std::cin >> input;
				wanted.push_back(input);
			}

			std::stack<int> station{};
			
			while (checking != trainCount) {
				if (!trains.empty() && trains.front() == wanted.at(checking)) {
					trains.pop();
					++checking;
				}
				else if (!station.empty() && station.top() == wanted.at(checking)) {
					station.pop();
					++checking;
				}
				else {
					if (trains.empty()) {
						break;
					}
					station.push(trains.front());
					trains.pop();
				}
			}

			if (checking == trainCount) {
				std::cout << "Yes\n";
			}
			else {
				std::cout << "No\n";
			}
		}
		std::cout << '\n';
	}

	return 0;
}
