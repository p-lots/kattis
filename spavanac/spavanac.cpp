#include <iostream>

int main(int argc, char *argv[])
{
	int h, m;
	std::cin >> h >> m;
	int new_h = h, new_m = m - 45;
	if (new_m < 0) {
		if (h == 0) {
			new_h = 23;
		}
		else {
			new_h--;
		}
		new_m += 60;
	}
	std::cout << new_h << ' ' << new_m;
	return 0;
}