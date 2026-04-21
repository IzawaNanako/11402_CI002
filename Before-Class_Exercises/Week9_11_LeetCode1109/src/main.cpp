#include <cstddef>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> corpFlightBookings(std::vector<std::vector<int>>& bookings, int n) {
        std::vector<int> difference(n + 1, 0);

        for (std::vector<int>& vec : bookings) {
            int first{ vec.at(0) - 1 };
            int last{ vec.at(1) };
            int seats{ vec.at(2) };

            difference.at(first) += seats;
            difference.at(last) -= seats;
        }

        std::vector<int> answer(n, 0);
        answer.at(0) = difference.at(0);

        for (size_t i{ 1 }; i < n; ++i) {
            answer.at(i) = answer.at(i - 1) + difference.at(i);
        }

        return answer;
    }
};
