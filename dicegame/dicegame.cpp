#include <iostream>

int main(int argc, char *argv[])
{
	int gunnar[4], emma[4];
	for (int i = 0; i < 8; i++) {
		if (i < 4) {
			std::cin >> gunnar[i];
		}
		else {
			std::cin >> emma[i % 4];
		}
	}
	double sum = 0, count = 0;
	for (int i = gunnar[0]; i <= gunnar[1]; i++) {
		sum += i;
		count++;
	}
	double gu_d_a_avg = sum / count;
	sum = 0;
	count = 0;
	for (int i = gunnar[2]; i <= gunnar[3]; i++) {
		sum += i;
		count++;
	}
	double gu_d_b_avg = sum / count;
	sum = 0;
	count = 0;
	for (int i = emma[0]; i <= emma[1]; i++) {
		sum += i;
		count++;
	}
	double em_d_a_avg = sum / count;
	sum = 0;
	count = 0;
	for (int i = emma[2]; i <= emma[3]; i++) {
		sum += i;
		count++;
	}
	double em_d_b_avg = sum / count;
	double gu_d_avg = (gu_d_a_avg + gu_d_b_avg) / 2.0;
	double em_d_avg = (em_d_a_avg + em_d_b_avg) / 2.0;
	if (gu_d_avg > em_d_avg) {
		std::cout << "Gunnar";
	}
	else if (em_d_avg > gu_d_avg) {
		std::cout << "Emma";
	}
	else {
		std::cout << "Tie";
	}
	return 0;
}