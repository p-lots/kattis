#include <iostream>

int main(int argc, char *argv[])
{
	int n, p, q;
	std::cin >> n >> p >> q;
	if (((p + q) % (n * 2)) < n) {
		std::cout << "paul";
	}
	else {
		std::cout << "opponent";
	}
	return 0;
}