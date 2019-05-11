#include <cmath>
#include <iomanip>
#include <iostream>

int main(int argc, char *argv[])
{
	double r;
	int m, c;
	static const double PI = std::acos(-1.0);
	while (std::cin >> r >> m >> c) {
		if (r == 0.0 && m == 0 && c == 0) {
			break;
		}
		double area_of_circle = PI * r * r;
		double area_of_square = std::pow(r * static_cast<double>(2), 2);
		double square_to_circle_ratio =
			static_cast<double>(c) / static_cast<double>(m);
		std::cout << std::setprecision(10) << std::fixed
			<< area_of_circle << ' '
			<< static_cast<double>(area_of_square * square_to_circle_ratio);
		std::cout << '\n';
	}
	return 0;
}