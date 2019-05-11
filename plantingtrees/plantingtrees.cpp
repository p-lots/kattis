#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
	int num_trees;
	std::cin >> num_trees;
	int time_to_grow;
	std::vector<int> grow_vec;
	while (std::cin >> time_to_grow) {
		grow_vec.push_back(time_to_grow);
	}
	std::sort(grow_vec.rbegin(), grow_vec.rend());
	std::vector<int> day_of_full_growth;
	for (unsigned i = 0; i < grow_vec.size(); i++) {
		day_of_full_growth.push_back((i + 1) + grow_vec[i] + 1);
	}
	int result = *(std::max_element(day_of_full_growth.begin(), day_of_full_growth.end()));
	std::cout << result;
	return 0;
}