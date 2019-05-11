#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string input;

	std::cin >> input;

	int count = 0;

	for (unsigned i = 0; i < input.length(); i++) {
		switch (i % 3) {
			case 0: 
				if (input[i] != 'P') count++;
			break;
			case 1:
				if (input[i] != 'E') count++;
			break;
			case 2:
				if (input[i] != 'R') count++;
			break;
			default: break;
		}
	}

	std::cout << count;

	return 0;
}