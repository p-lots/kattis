#include <cmath>
#include <iostream>

int main()
{
	int n, w, h;
	std::cin >> n >> w >> h;
	int len;
	int hyp = std::sqrt(std::pow(w, 2) + std::pow(h, 2));
	while (n--) {
		std::cin >> len;
		if (len <= hyp) std::cout << "DA\n";
		else std::cout << "NE\n";
	}
	return 0;
}