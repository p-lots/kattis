#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	int count;
	std::cin >> count;
	for (unsigned i = 1; i <= count; i++) {
		std::cout << i << " Abracadabra\n";
	}
	return 0;
}