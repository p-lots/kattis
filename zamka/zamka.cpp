#include <algorithm>
#include <limits>
#include <iostream>

int sum_of_digits(int);

int main(int argc, char *argv[])
{
	int l, d, x;
	std::cin >> l >> d >> x;
	int max = std::numeric_limits<int>::min(), min = std::numeric_limits<int>::max();
	for (int i = l; i <= d; i++) {
		int sum_of_d = sum_of_digits(i);
		if (sum_of_d == x) {
			min = std::min(min, i);
			max = std::max(max, i);
		}
	}
	std::cout << min << '\n' << max;
	return 0;
}

int sum_of_digits(int n)
{
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}