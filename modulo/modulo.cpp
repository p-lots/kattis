#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
	std::vector<int> input;
	int n;
	while (std::cin >> n) {
		input.push_back(n);
	}
	std::transform(input.begin(), input.end(), input.begin(),
		[](const int &n) {
			return n % 42;
		});
	std::sort(input.begin(), input.end());
	std::cout << std::distance(input.begin(), std::unique(input.begin(), input.end()));
	return 0;
}