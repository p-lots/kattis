#include <iomanip>
#include <iostream>
#include <cmath>

const double PI = std::acos(-1.0);

double area_of_circle(double r)
{
	return PI * r * r;
}

int main(int argc, char *argv[])
{
	double c, r;
	std::cin >> r >> c;
	double area_pizza = area_of_circle(r);
	double percent_area_cheese = (area_of_circle(r - c) / area_pizza) * 100.0;
	std::cout << std::setprecision(10) << std::fixed << percent_area_cheese;
	return 0;
}
