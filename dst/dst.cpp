#include <iostream>

int main()
{
	int cases;
	std::cin >> cases;
	while (cases--) {
		char forward_or_backward;
		int d, h, m;
		std::cin >> forward_or_backward >> d >> h >> m;
		if (d == 0)
			std::cout << h << ' ' << m << '\n';
		else if (forward_or_backward == 'F') {
			int minutes_after = m + d;
			if (minutes_after >= 60 && minutes_after < 120) {
				minutes_after %= 60;
				h += 1;
				if (h > 23) {
					h = 0;
				}
			}
			else if (minutes_after >= 120) {
				minutes_after %= 60;
				h += 2;
				if (h == 24) {
					h = 0;
				}
				else if (h == 25) {
					h = 1;
				}
			}
			std::cout << h << ' ' << minutes_after << '\n';
		}
		else if (forward_or_backward == 'B') {
			int minutes_after = m - d;
			if (minutes_after < 0 && minutes_after >= -60) {
				minutes_after += 60;
				h -= 1;
				if (h < 0) {
					h = 23;
				}
			}
			else if (minutes_after < -60) {
				minutes_after += 120;
				h -= 2;
				if (h == -1) {
					h = 23;
				}
				else if (h == -2) {
					h = 22;
				}
			}
			std::cout << h << ' ' << minutes_after << '\n';
		}
	}
	return 0;
}