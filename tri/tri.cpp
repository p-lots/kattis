#include <iostream>

bool make_eq(int a, int b, int c, int &op) {
	switch (op) {
		case 0: 
			return a + b == c;
		case 1: 
			return a - b == c;
		case 2: 
			return a * b == c;
		case 3:
			return a / b == c;
		case 4:
			return a == b + c;
		case 5:
			return a == b - c;
		case 6:
			return a == b * c;
		case 7:
			return a == b / c;
		default:
			op = -1;
			return false;
	}
}

int main(int argc, char *argv[])
{
	int a, b, c, op = 0;
	std::cin >> a >> b >> c;
	while (!make_eq(a, b, c, op)) {
		if (op == -1) {
			break;
		}
		op++;
	}
	switch (op) {
		case 0: 
			std::cout << a << "+" << b << "=" << c;
			break;
		case 1: 
			std::cout << a << "-" << b << "=" << c;
			break;
		case 2: 
			std::cout << a << "*" << b << "=" << c;
			break;
		case 3:
			std::cout << a << "/" << b << "=" << c;
			break;
		case 4:
			std::cout << a << "=" << b << "+" << c;
			break;
		case 5:
			std::cout << a << "=" << b << "-" << c;
			break;
		case 6:
			std::cout << a << "=" << b << "*" << c;
			break;
		case 7:
			std::cout << a << "=" << b << "/" << c;
			break;
		default:
			std::cout << "Error: solution not found\n";
			break;
	}
	return 0;
}