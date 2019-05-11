#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
	int r, c, z_r, z_c, r_copy;
	std::string line;
	std::getline(std::cin, line);
	std::stringstream ss(line);
	ss >> r >> c >> z_r >> z_c;
	r_copy = r;
	std::vector<std::string> article;
	while (r_copy--) {
		std::getline(std::cin, line);
		article.push_back(line);
	}
	std::vector<std::string> result;
	for (std::string s : article) {
		std::string output_line;
		for (char c : s) {
			output_line.push_back(c);
			for (unsigned i = 1; i < z_c; i++) {
				output_line.push_back(c);
			}
		}
		result.push_back(output_line);
		for (unsigned i = 1; i < z_r; i++) {
			result.push_back(output_line);
		}
	}
	for (std::string s : result) {
		std::cout << s << '\n';
	}
	return 0;
}