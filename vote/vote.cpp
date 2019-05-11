#include <iostream>

int main()
{
	int cases;
	std::cin >> cases;
	while (cases--) {
		int num_candidates;
		std::cin >> num_candidates;
		unsigned long long first = 0, second = 0, winning_candidate = 0, total = 0;
		int current_candidate = 1;
		while (num_candidates--) {
			unsigned long long temp;
			std::cin >> temp;
			total += temp;
			if (temp > first) {
				second = first;
				first = temp;
				winning_candidate = current_candidate;
			}
			else if (temp > second) second = temp;
			current_candidate++;
		}
		if (first == second) std::cout << "no winner";
		else {
			if (first > total - first) std::cout << "majority winner " << winning_candidate;
			else std::cout << "minority winner " << winning_candidate;
		}
		std::cout << '\n';
	}
	return 0;
}