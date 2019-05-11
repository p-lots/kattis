#include <cmath>
#include <iostream>

int main()
{
	int input;
	std::cin >> input;
	unsigned long long result = 0ULL, points_per_side = 2ULL;
	for (unsigned i = 0; i < input; i++) {
		points_per_side += points_per_side - 1;
		result = std::pow(points_per_side, 2);
	}
	std::cout << result;
	return 0;
}