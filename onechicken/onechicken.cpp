#include <iostream>

int main()
{
	int n, m;
	std::cin >> n >> m;
	if (n > m) 
		std::cout << "Dr. Chaz needs " << n - m << " more piece" << (n - m > 1 ? "s" : "") << " of chicken!";
	else if (n < m) 
		std::cout << "Dr. Chaz will have " << m - n << " piece" << (m - n > 1 ? "s" : "") << " of chicken left over!";
	return 0;
}
