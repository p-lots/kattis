#include <cmath>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	int cases, case_counter = 0;
	std::cin >> cases;
	int line;

	unsigned long long sum = 0ULL;

	while (case_counter < cases) {
		std::cin >> line;
		sum += pow(line / 10, line % 10);
		case_counter++;
	}

	std::cout << sum;

	return 0;
}