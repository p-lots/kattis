#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <string>



std::string dec2bin(int n)
{
	int degree = static_cast<int>(std::log10(n) / std::log10(2));
	int digit;
	std::string ret;
	while (n > 0) {
		digit = n / std::pow(2, degree);
		ret += static_cast<char>(digit + '0');
		n -= std::pow(2, degree) * digit;
		if (degree > 0 && n == 0) {
			while (degree-- > 0) {
				ret += '0';
			}
			break;
		}
		degree--;
	}
	return ret;
}

unsigned long long bin2dec(std::string n)
{
	int ret = 0;
	int power = n.length() - 1;
	for (char c : n) {
		ret += pow(2, power--) * (c - '0');
	}
	return ret;
}

int main(int argc, char *argv[])
{
	int n;
	std::cin >> n;

	auto n_in_bin = dec2bin(n);

	std::string n_in_bin_rev;
	std::copy(n_in_bin.rbegin(), n_in_bin.rend(), std::back_inserter(n_in_bin_rev));

	auto result = bin2dec(n_in_bin_rev);
	std::cout << result;

	return 0;
}