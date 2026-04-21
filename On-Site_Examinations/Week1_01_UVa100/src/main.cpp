#include <algorithm>
#include <iostream>

static void solution(unsigned int i, unsigned int j) {
    // Print the pair of numbers first, so they could be swapped right after.
    std::cout << i << ' ' << j << ' ';

    // Reorder the numbers for easier processing.
    if (i > j) {
        std::swap(i, j);
    }

    // Initialize max cycle count.
    unsigned int maxCycle{ 0 };

    // Cycle through every number within the two inputs.
    for (unsigned int cur{ i }; cur <= j; ++cur) {
        unsigned int n{ cur };
        // "1" is always counted, so the cycle count always start at 1.
        unsigned int curCycle{ 1 };

        // Process the 3n + 1 algorithm until n = 1.
        while (n != 1) {
            if (n % 2 != 0) {
                n = 3 * n + 1;
            }
            else {
                n /= 2;
            }

            // If the cycle happens (n != 1), add 1 to current cycle count.
            ++curCycle;
        }

        // If current cycle count is bigger than the max cycle count, store it.
        if (curCycle > maxCycle) {
            maxCycle = curCycle;
        }
    }

    // Print the max cycle count.
    std::cout << maxCycle << '\n';
}

int main() {
    // Input and output optimizations.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Input variables initializations.
    unsigned int iInput{};
    unsigned int jInput{};

    // Process inputs until EOF.
    while (std::cin >> iInput >> jInput) {
        solution(iInput, jInput);
    }

    return 0;
}
