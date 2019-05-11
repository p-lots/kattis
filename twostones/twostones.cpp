#include <iostream>

int main(int argc, char *argv[])
{
	int input;
	std::cin >> input;
	std::cout << (input % 2 == 0 ? "Bob" : "Alice");
	return 0;
}