#include <iostream>

int main(int argc, char *argv[])
{
	int x, y, n;

	std::cin >> x >> y >> n;

	for (int i = 1; i <= n; i++) {
		if ((i % x == 0) && (i % y == 0)) {
			std::cout << "FizzBuzz";
		}
		else if (i % x == 0) {
			std::cout << "Fizz";
		}
		else if (i % y == 0) {
			std::cout << "Buzz";
		}
		else {
			std::cout << i;
		}
		std::cout << '\n';
	}

	return 0;
}