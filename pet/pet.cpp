#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

int main(int argc, char *argv[])
{
	int contestant = 1, a, b, c, d;
	std::vector<std::pair<int, int> > scores;
	while (std::cin >> a >> b >> c >> d) {
		int sum = a + b + c + d;
		scores.push_back(std::make_pair(contestant++, sum));
	}
	auto it = std::max_element(scores.begin(), scores.end(),
		[](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
			return lhs.second < rhs.second;
		});
	std::cout << it->first << ' ' << it->second;
	return 0;
}