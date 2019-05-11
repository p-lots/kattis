#include <iostream>

int main()
{
	int max, n;
	std::cin >> max >> n;
	int prev = max;
	while (n--) {
		int current;
		std::cin >> current;
		prev = prev - current + max;
	}
	std::cout << prev;
	return 0;
}