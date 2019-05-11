#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string temp;
	bool first_time = true;
	int num_numbers = 0;

	while (std::getline(std::cin, temp)) {
		if (first_time) {
			num_numbers = std::stoi(temp);
			first_time = false;
		}
		else {
			if (num_numbers > 0) {
				int n = std::stoi(temp);
				std::cout << n << " is " << (n % 2 == 0 ? "even\n" : "odd\n");
				num_numbers--;
			}
		}
	}

	return 0;
}