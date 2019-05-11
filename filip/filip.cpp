#include <algorithm>
#include <iostream>
#include <string>

int main()
{
	int n1, n2;
	std::cin >> n1 >> n2;
	std::string n1_str = std::to_string(n1), n2_str = std::to_string(n2);
	std::reverse(n1_str.begin(), n1_str.end());
	std::reverse(n2_str.begin(), n2_str.end());
	n1 = std::stoi(n1_str);
	n2 = std::stoi(n2_str);
	std::cout << (n1 > n2 ? n1 : n2);
	return 0;
}