#include <iostream>

int main(int argc, char *argv[])
{
	int gu_d_a, gu_d_b, gu_d_c, gu_d_d;
	int em_d_a, em_d_b, em_d_c, em_d_d;
	std::cin >> gu_d_a >> gu_d_b >> gu_d_c >> gu_d_d;
	std::cin >> em_d_a >> em_d_b >> em_d_c >> em_d_d;
	int sum = 0;
	int count = 0;
	double gu_d_a_avg, gu_d_b_avg, em_d_a_avg, em_d_b_avg;
	for (int i = gu_d_a; i <= gu_d_b; i++) {
		sum += i;
		count++;
	}
	gu_d_a_avg = static_cast<double>(sum) / static_cast<double>(count);
	sum = 0;
	count = 0;
	for (int i = gu_d_c; i <= gu_d_d; i++) {
		sum += i;
		count++;
	}
	gu_d_b_avg = static_cast<double>(sum) / static_cast<double>(count);
	sum = 0;
	count = 0;
	for (int i = em_d_a; i <= em_d_b; i++) {
		sum += i;
		count++;
	}
	em_d_a_avg = static_cast<double>(sum) / static_cast<double>(count);
	sum = 0;
	count = 0;
	for (int i = em_d_c; i <= em_d_d; i++) {
		sum += i;
		count++;
	}
	em_d_b_avg = static_cast<double>(sum) / static_cast<double>(count);
	double gu_d_avg = (gu_d_a_avg + gu_d_b_avg) / 2.0;
	double em_d_avg = (em_d_a_avg + em_d_b_avg) / 2.0;
	if (gu_d_avg > em_d_avg) {
		std::cout << "Gunnar";
	}
	else if (gu_d_avg < em_d_avg) {
		std::cout << "Emma";
	}
	else {
		std::cout << "Tie";
	}
	return 0;
}