#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

int clamp(const int v, const int lo, const int hi)
{
	if (v < hi) {
		return std::max(v, lo);
	}
	else {
		return std::min(v, hi);
	}
}

int main(int argc, char *argv[])
{
	int w, l;
	while (std::cin >> w >> l) {
		if (w == 0 && l == 0) {
			break;
		}
		int num_walks;
		std::vector<std::pair<char, int> > walks;
		std::cin >> num_walks;
		while (num_walks--) {
			char direction;
			int steps;
			std::cin >> direction >> steps;
			walks.push_back(std::make_pair(direction, steps));
		}
		int thinks_x = 0, thinks_y = 0, actual_x = 0, actual_y = 0;
		for (const auto walk_pair : walks) {
			switch (walk_pair.first) {
				case 'u':
				actual_y += walk_pair.second;
				actual_y = clamp(actual_y, 0, l - 1);
				thinks_y += walk_pair.second;
				break;
				case 'd':
				actual_y -= walk_pair.second;
				actual_y = clamp(actual_y, 0, l - 1);
				thinks_y -= walk_pair.second;
				break;
				case 'l':
				actual_x -= walk_pair.second;
				actual_x = clamp(actual_x, 0, w - 1);
				thinks_x -= walk_pair.second;
				break;
				case 'r':
				actual_x += walk_pair.second;
				actual_x = clamp(actual_x, 0, w - 1);
				thinks_x += walk_pair.second;
				break;
				default:
				break;
			}
		}
		std::cout << "Robot thinks " << thinks_x << ' ' << thinks_y << '\n';
		std::cout << "Actually at " << actual_x << ' ' << actual_y << '\n';
		std::cout << '\n';
	}
	return 0;
}
