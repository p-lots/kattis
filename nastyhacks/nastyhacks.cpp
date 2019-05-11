#include <iostream>

int main(int argc, char *argv[])
{
	int cases;
	std::cin >> cases;
	int r, e, c;
	while (cases--) {
		std::cin >> r >> e >> c;
		std::cout << (r < e - c ? "advertise\n"
								: r > e - c ? "do not advertise\n"
											: "does not matter\n");
	}
	return 0;
}