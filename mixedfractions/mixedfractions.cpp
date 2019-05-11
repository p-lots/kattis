#include <iostream>

int main(int argc, char *argv[])
{
	int num, denom;
	while (std::cin >> num >> denom) {
		if (num == 0 && denom == 0) break;
		int whole_number = num / denom;
		int new_num = num % denom;
		std::cout << whole_number << ' ' << new_num << " / " << denom << '\n';
	}
	return 0;
}
