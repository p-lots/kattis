#include <algorithm>
#include <iostream>
#include <vector>

typedef unsigned long long int U64;

std::vector<U64> make_vec_excluding(std::vector<U64> &, std::vector<U64>::iterator &);

int main(int argc, char *argv[])
{
	int num_cases, case_number = 1;
	std::cin >> num_cases;
	while (num_cases--) {
		std::vector<U64> ids;
		int num_guests;
		std::cin >> num_guests;
		while (num_guests--) {
			U64 c;
			std::cin >> c;
			ids.push_back(c);
		}
		U64 result;
		for (auto it = ids.begin(); it != ids.end(); it++) {
			auto new_vec = make_vec_excluding(ids, it);
			auto find_it = std::find(new_vec.begin(), new_vec.end(), *it);
			if (find_it == new_vec.end()) {
				result = *it;
				break;
			}
		}
		std::cout << "Case #" << case_number++ << ": " << result << '\n';
	}
	return 0;
}

std::vector<U64> make_vec_excluding(std::vector<U64> &vec, std::vector<U64>::iterator &it)
{
	std::vector<U64> ret;
	ret.insert(ret.end(), vec.begin(), it);
	ret.insert(ret.end(), it + 1, vec.end());
	return ret;
}