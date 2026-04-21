#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cases{};
    std::cin >> cases;

    for (int i{ 0 }; i < cases; ++i) {
        int count{};
        std::cin >> count;
        std::vector<int> train{};
        int swaps{ 0 };
        for (int j{ 0 }; j < count; ++j) {
            int input;
            std::cin >> input;
            train.push_back(input);
        }

        for (int m{ 0 }; m < train.size(); ++m) {
            for (int n{ m }; n < train.size(); ++n) {
                if (train.at(n) < train.at(m)) {
                    std::swap(train.at(n), train.at(m));
                    ++swaps;
                }
            }
        }

        std::cout << "Optimal train swapping takes " << swaps << " swaps.\n";
    }

    return 0;
}
