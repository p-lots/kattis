#include <cmath>
#include <iostream>

long double deg_to_rad(int deg)
{
	static const long double pi = std::acos(-1.0);
	return (pi / static_cast<long double>(180)) * static_cast<long double>(deg);
}

int main(int argc, char *argv[])
{
	int h, v_deg;
	std::cin >> h >> v_deg;
	auto v_rad = deg_to_rad(v_deg);
	int result = std::ceil(static_cast<long double>(h) / std::sin(v_rad));
	std::cout << result;
	return 0;
}