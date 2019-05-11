#include <iostream>
#include <vector>

typedef unsigned long long int U64;

int main(int argc, char *argv[])
{
	int num_cases, case_number = 1;
	std::cin >> num_cases;
	while (num_cases--) {
		std::vector<U64> ids;
		int num_guests;
		U64 oddmanout, first_c;
		std::cin >> num_guests;
		while (num_guests--) {
			U64 c;
			bool find_first = true;
			std::cin >> c;
			if (!ids.empty()) {
				auto it = std::find(ids.begin(), ids.end(), c);
				if (it != ids.end()) {
					ids.erase(it);
				}
				else {
					oddmanout = c;
				}
				if (find_first) {
					it = std::find(ids.begin(), ids.end(), first_c);
					if (it != ids.end()) {
						ids.erase(it);
					}
					else {
						oddmanout = first_c;
					}
					find_first = false;
				}
			}
			else {
				ids.push_back(c);
				first_c = c;
			}
		}
		std::cout << "Case #" << case_number++ << ": " << oddmanout << '\n';
	}
}