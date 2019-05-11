#include <cmath>
#include <iomanip>
#include <iostream>

int main(int argc, char *argv[])
{
	double area;
	std::cin >> area;
	double result = std::sqrt(area) * 4.0;
	std::cout << std::setprecision(10) << std::fixed << result;
	return 0;
}
