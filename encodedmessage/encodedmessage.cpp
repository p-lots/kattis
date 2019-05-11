#include <cmath>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	int cases;
	std::cin >> cases;
	while (cases-- > 0) {
		std::string line;
		std::cin >> line;
		int side_len = std::sqrt(line.length());
		char encoded_message[side_len][side_len];
		unsigned i = 0;
		for (unsigned j = 0; j < side_len; j++) {
			for (unsigned k = 0; k < side_len; k++) {
				encoded_message[j][k] = line.at(i++);
			}
		}
		std::string decoded_message;
		for (int k = side_len - 1; k > -1; k--) {
			for (int j = 0; j < side_len; j++) {
				decoded_message.push_back(encoded_message[j][k]);
			}
		}
		for (char c : decoded_message) {
			std::cout << c;
		}
		std::cout << '\n';
	}
	return 0;
}
