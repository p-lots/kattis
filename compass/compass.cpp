#include <iostream>

int main(int argc, char *argv[])
{
	int current_deg, correct_deg;
	std::cin >> current_deg >> correct_deg;
	int change = correct_deg - current_deg;
	if (change > 180) {
		change -= 360;
	}
	else if (change < -180) {
		change += 360;
	}
	if (change == -180) {
		change *= -1;
	}
	std::cout << change;
	return 0;
}