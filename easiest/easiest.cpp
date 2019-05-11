#include <iostream>

int sum_of_digits(int n)
{
	int ret = 0;
	while (n > 0) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main(int argc, char *argv[])
{
	int N;
	while (std::cin >> N) {
		if (N == 0) break;
		int target = sum_of_digits(N), output = 11;
		while (sum_of_digits(output * N) != target) {
			output++;
		}
		std::cout << output << '\n';
	}
	return 0;
}
