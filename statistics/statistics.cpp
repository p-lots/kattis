#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
	int temp, counter = 1;
	while (std::cin >> temp) {
		int n = temp;
		std::vector<int> numbers;
		while (n-- > 0) {
			std::cin >> temp;
			numbers.push_back(temp);
		}
		int minimum = *(std::min_element(numbers.begin(), numbers.end()));
		int maximum = *(std::max_element(numbers.begin(), numbers.end()));
		int range = maximum - minimum;
		std::cout << "Case " << counter++ << ": ";
		std::cout << minimum << ' ' << maximum << ' ' << range << '\n';
	}
	return 0;
}