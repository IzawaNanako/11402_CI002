#include <iostream>

static void solution(unsigned int first, unsigned int second) {
    // Variable to store total carry count.
    unsigned short carries{ 0 };
    // Variable to remember if a carry happened on previous digit.
    bool carry{ 0 };

    // Loop until every digit is processed.
    while (first > 0 || second > 0) {
        // Determine if a carry operation happens, if it does, remember the occurence and add 1 to carry count, otherwise reset the carry variable.
        if ((first % 10 + second % 10 + carry) >= 10) {
            carry = 1;
            ++carries;
        }
        else {
            carry = 0;
        }
        
        // Go to the next digit to process.
        first /= 10;
        second /= 10;
    }

    // Handles output variations then print the output.
    if (carries == 0) {
        std::cout << "No carry operation.\n";
    }
    else if (carries == 1) {
        std::cout << "1 carry operation.\n";
    }
    else {
        std::cout << carries << " carry operations.\n";
    }
}

int main() {
    // Input and output optimizations.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Input variables initializations.
    unsigned int numOne{};
    unsigned int numTwo{};
    // Enter first pair of numbers first to prepare for the loop.
    std::cin >> numOne >> numTwo;

    // Stop processing the numbers if both numbers are 0.
    while ((numOne != 0) || (numTwo != 0)) {
        solution(numOne, numTwo);
        std::cin >> numOne >> numTwo;
    }

    return 0;
}
