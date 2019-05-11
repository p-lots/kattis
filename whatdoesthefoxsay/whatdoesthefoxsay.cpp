#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> tokenize(std::string line)
{
	std::vector<std::string> ret;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, ' ')) {
		ret.push_back(temp);
	}
	return ret;
}

int main()
{
	std::string line;
	std::getline(std::cin, line);
	int cases = std::stoi(line);
	while (cases--) {
		std::getline(std::cin, line);
		std::vector<std::string> recording = tokenize(line);
		std::vector<std::string> noises;
		while (line != "what does the fox say?") {
			std::getline(std::cin, line);
			if (line == "what does the fox say?") break;
			auto temp = tokenize(line);
			noises.push_back(temp.back());
		}
		auto rec_it = recording.begin();
		for (auto noise_it = noises.begin(); noise_it != noises.end(); noise_it++) {
			while ((rec_it = std::find(recording.begin(), recording.end(), *noise_it)) != recording.end()) {
				rec_it = recording.erase(rec_it);
			}
		}
		for (auto it = recording.begin(); it != recording.end(); it++) {
			std::cout << *it << ' ';
		}
		std::cout << '\n';
	}
	return 0;
}