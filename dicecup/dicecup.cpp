#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <utility>
#include <vector>

int main(int argc, char *argv[])
{
	int d1, d2;
	std::cin >> d1 >> d2;
	std::vector<int> d_vec1(d1), d_vec2(d2);
	std::iota(d_vec1.begin(), d_vec1.end(), 1);
	std::iota(d_vec2.begin(), d_vec2.end(), 1);
	std::vector<int> sums;
	for (int n : d_vec1) {
		for (int m : d_vec2) {
			sums.push_back(n + m);
		}
	}
	// std::sort(sums.begin(), sums.end());
	std::map<int, int> count_of_sums;
	for (int n : sums) {
		count_of_sums[n]++;
	}
	auto it = std::max_element(count_of_sums.begin(), count_of_sums.end(),
		[](const std::pair<const int, int> &lhs, const std::pair<const int, int> &rhs) {
			return lhs.second < rhs.second;
		});
	std::vector<int> result_vec;
	for (auto &p : count_of_sums) {
		if (p.second == it->second) {
			result_vec.push_back(p.first);
		}
	}
	std::sort(result_vec.begin(), result_vec.end());
	for (int n : result_vec) {
		std::cout << n << '\n';
	}
	return 0;
}