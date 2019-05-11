#include <iostream>

int main(int argc, char *argv[])
{
	int sour_jars, sweet_jars;
	while (std::cin >> sweet_jars >> sour_jars) {
		if (sweet_jars == 0 && sour_jars == 0) {
			break;
		}
		else if (sweet_jars + sour_jars == 13) {
			std::cout << "Never speak again.\n";
		}
		else if (sour_jars > sweet_jars) {
			std::cout << "Left beehind.\n";
		}
		else if (sweet_jars > sour_jars) {
			std::cout << "To the convention.\n";
		}
		else if (sweet_jars == sour_jars) {
			std::cout << "Undecided.\n";
		}
	}
	return 0;
}
