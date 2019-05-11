#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> make_int_vec(std::string);

std::vector<bool> make_dog_bool_vec(std::vector<int>, int, int);

int main(int argc, char *argv[])
{
	std::string temp;
	bool first_time = true;
	std::vector<int> dog_vec, worker_vec;

	while (std::getline(std::cin, temp)) {
		if (first_time) {
			dog_vec = make_int_vec(temp);
			first_time = false;
		}
		else {
			worker_vec = make_int_vec(temp);
		}
	}

	std::vector<bool> dog1 = make_dog_bool_vec(worker_vec, dog_vec[0], dog_vec[1]);
	std::vector<bool> dog2 = make_dog_bool_vec(worker_vec, dog_vec[2], dog_vec[3]);
	for (int i : worker_vec) {
		if (dog1[i - 1] && dog2[i - 1]) {
			std::cout << "both\n";
		}
		else if ((dog1[i - 1] && !(dog2[i - 1])) || (!(dog1[i - 1]) && dog2[i - 1])) {
			std::cout << "one\n";
		}
		else {
			std::cout << "none\n";
		}
	}

	return 0;
}

std::vector<int> make_int_vec(std::string line)
{
	std::vector<int> ret;
	std::string temp_str;
	std::stringstream ss(line);

	while (std::getline(ss, temp_str, ' ')) {
		ret.push_back(std::stoi(temp_str));
	}

	return ret;
}

std::vector<bool> make_dog_bool_vec(std::vector<int> worker_vec, int start, int end)
{
	auto iter = std::max_element(worker_vec.begin(), worker_vec.end());
	int max_elem = *iter;

	std::vector<bool> ret(max_elem, false);
	int start_counter = 0, end_counter = 0;

	for (auto it = ret.begin(); it != ret.end(); it++) {
		if (start_counter < start && end_counter == 0) {
			*it = true;
			start_counter++;
		}
		else if (start_counter == start && end_counter < end) {
			end_counter++;
		}
		else if (end_counter == end) {
			start_counter = 0;
			end_counter = 0;
			*it = true;
			start_counter++;
		}
	}

	return ret;
}