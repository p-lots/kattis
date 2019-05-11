#include <iostream>

int main()
{
	int a, i;
	std::cin >> a >> i;
	if (a == 1) std::cout << i;
	else std::cout << a * i - (a - 1);
	return 0;
}