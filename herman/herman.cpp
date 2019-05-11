#include <cmath>
#include <iomanip>
#include <iostream>

int main(int argc, char *argv[])
{
	static const long double pi = std::acos(-1.0);
	double r;
	std::cin >> r;
	double euc_cir = pi * r * r, taxi_cir = 2 * r * r;
	std::cout << std::setprecision(10) << std::fixed << euc_cir << '\n' << taxi_cir << '\n';
	return 0;
}
