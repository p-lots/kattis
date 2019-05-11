#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main(int argc, char *argv[])
{
	int num_cases, case_counter = 0;

	std::cin >> num_cases;

	while (case_counter < num_cases) {
		int data_set_number, count;

		std::cin >> data_set_number >> count;

		std::vector<int> positive_ints(count), odd_ints(count), even_ints(count);

		std::iota(positive_ints.begin(), positive_ints.end(), 1);
		int n = -1;
		std::generate(odd_ints.begin(), odd_ints.end(), [&n]{ return n += 2; });
		n = 0;
		std::generate(even_ints.begin(), even_ints.end(), [&n]{ return n += 2; });

		int sum_positive_ints = std::accumulate(positive_ints.begin(),
			positive_ints.end(), 0);
		int sum_odd_ints = std::accumulate(odd_ints.begin(),
			odd_ints.end(), 0);
		int sum_even_ints = std::accumulate(even_ints.begin(),
			even_ints.end(), 0);

		std::cout << data_set_number << ' ' << sum_positive_ints << ' ';
		std::cout << sum_odd_ints << ' ' << sum_even_ints << '\n';

		case_counter++;
	}

	return 0;
}