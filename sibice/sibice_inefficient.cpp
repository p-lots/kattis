#include <cmath>
#include <iostream>
#include <vector>

int main()
{
	int n, w, h;
	std::cin >> n >> w >> h;
	int len;
	std::vector<int> lens;
	while (n--) {
		std::cin >> len;
		lens.push_back(len);
	}
	int hyp = std::sqrt(std::pow(w, 2) + std::pow(h, 2));
	for (int num : lens) {
		if (num < hyp) std::cout << "DA\n";
		else std::cout << "NE\n";
	}
	return 0;
}