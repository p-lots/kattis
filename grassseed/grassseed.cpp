#include <iostream>
#include <iomanip>

int main(int argc, char *argv[])
{
	int num_lawns, lawn_counter = 0;
	double cost_per_meter;
	double total_cost = 0.0F;
	std::cin >> cost_per_meter >> num_lawns;
	while (lawn_counter < num_lawns) {
		double lawn_length, lawn_width;
		std::cin >> lawn_length >> lawn_width;
		total_cost += lawn_length * lawn_width * cost_per_meter;
		lawn_counter++;
	}
	std::cout << std::fixed << std::setprecision(10) << total_cost;
	return 0;
}