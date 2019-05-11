#include <cmath>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	int number_of_cases, current_case = 0;
	std::cin >> number_of_cases;
	double v0, theta, x1, h1, h2;

	while (current_case < number_of_cases) {
		std::cin >> v0 >> theta >> x1 >> h1 >> h2;
		theta = theta * 3.141592653589793 / 180.0;
		double t = x1 / (std::cos(theta) * v0);
		double y = (v0 * t * std::sin(theta)) - (0.5 * 9.81 * t * t);
		std::cout << (h1 + 1 <= y && h2 - 1 >= y ? "Safe" : "Not Safe") << '\n';
		current_case++;
	}
	return 0;
}