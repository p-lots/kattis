#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

int main(int argc, char *argv[])
{
	int list_size;

	std::cin >> list_size;

	while (list_size != 0) {
		std::set<int> set1, set2;
		std::vector<int> list1_given;

		int list_item_counter = 0;

		while (list_item_counter < list_size * 2) {
			int temp;
			std::cin >> temp;
			if (list_item_counter < list_size) {
				set1.insert(temp);
				list1_given.push_back(temp);
			}
			else {
				set2.insert(temp);
			}

			list_item_counter++;
		}

		std::map<int, int> lookup_table;

		auto set1_it = set1.begin();
		auto set2_it = set2.begin();

		while (set1_it != set1.end() && set2_it != set2.end()) {
			lookup_table.insert(std::make_pair(*set1_it, *set2_it));
			++set1_it;
			++set2_it;
		}

		std::vector<int> output;

		for (auto it = list1_given.begin();	it != list1_given.end(); it++) {
			output.push_back(lookup_table.at(*it));
		}

		for (int n : output) {
			std::cout << n << '\n';
		}

		std::cin >> list_size;
		if (list_size != 0) {
			std::cout << '\n';
		}
	}

	return 0;
}