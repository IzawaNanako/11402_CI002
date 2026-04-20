#include <iostream>
#include <iomanip>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	double x1{};
	double y1{};
	double x2{};
	double y2{};
	double x3{};
	double y3{};
	double x4{};
	double y4{};

	while (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
		if (x1 == x3 && y1 == y3) {
			std::cout << std::setprecision(3) << std::fixed << x4 - x1 + x2 << ' ' << y4 - y1 + y2;
		}
		else if (x1 == x4 && y1 == y4) {
			std::cout << std::setprecision(3) << std::fixed << x3 - x1 + x2 << ' ' << y3 - y1 + y2;
		}
		else if (x2 == x3 && y2 == y3) {
			std::cout << std::setprecision(3) << std::fixed << x4 - x2 + x1 << ' ' << y4 - y2 + y1;
		}
		else {
			std::cout << std::setprecision(3) << std::fixed << x3 - x2 + x1 << ' ' << y3 - y2 + y1;
		}

		std::cout << '\n';
	}

	return 0;
}
