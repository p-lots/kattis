#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{	
	int num_cases, case_counter = 0;

	std::cin >> num_cases;

	std::string line;

	while (case_counter < num_cases) {
		std::cin >> line;

		int len_sqrt = static_cast<int>(std::sqrt(line.length()));

		if (std::pow(len_sqrt, 2) != line.length()) {
			len_sqrt++;
		}

		char arr[len_sqrt][len_sqrt];

		unsigned k = 0;

		for (unsigned i = 0; i < len_sqrt; i++) {
			for (unsigned j = 0; j < len_sqrt; j++) {
				if (k < line.length()) {
					arr[i][j] = line[k++];
				}
				else {
					arr[i][j] = '*';
				}
			}
		}

		char arr2[len_sqrt][len_sqrt];

		unsigned l = len_sqrt - 1;
		
		for (unsigned i = 0; i < len_sqrt; i++) {
			k = 0;
			for (unsigned j = 0; j < len_sqrt; j++) {
				arr2[k][l] = arr[i][j];
				k++;
			}
			l--;
		}

		std::string result;

		for (unsigned i = 0; i < len_sqrt; i++) {
			for (unsigned j = 0; j < len_sqrt; j++) {
				if (arr2[i][j] != '*') {
					result.push_back(arr2[i][j]);
				}
			}
		}

		std::cout << result << '\n';

		case_counter++;
	}

	return 0;
}