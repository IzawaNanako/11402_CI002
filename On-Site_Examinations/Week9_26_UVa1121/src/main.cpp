#include <cstddef>
#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N{};
	int S{};

	while (std::cin >> N >> S) {
		std::vector<int> sequence{};
		int seqSum{ 0 };
		int seqLength{ 0 };
		int seqMinLength{ N + 1 };
		size_t curIdx{ 0 };
		for (int i{ 0 }; i < N; ++i) {
			int input{};
			std::cin >> input;
			sequence.push_back(input);

			seqSum += input;
			++seqLength;

			if (seqSum >= S) {
				while (curIdx < i && seqSum - sequence.at(curIdx) >= S) {
					seqSum -= sequence.at(curIdx);
					++curIdx;
					--seqLength;
				}

				if (seqLength < seqMinLength) {
					seqMinLength = seqLength;
				}
			}
		}

		if (seqMinLength <= N) {
			std::cout << seqMinLength << '\n';
		}
		else {
			std::cout << 0 << '\n';
		}
	}

	return 0;
}
