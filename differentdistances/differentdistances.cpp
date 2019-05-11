#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

typedef struct {
	double x1;
	double y1;
	double x2;
	double y2;
} Coords;

std::vector<double> tokenize(std::string line)
{
	std::vector<double> ret;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, ' ')) {
		ret.push_back(std::stod(temp));
	}
	return ret;
}

double calculate_distance(Coords coords, double p)
{
	return std::pow(std::pow(std::fabs(coords.x1 - coords.x2), p)
		+ std::pow(std::fabs(coords.y1 - coords.y2), p), 1.0F/p);
}

int main(int argc, char *argv[])
{
	std::string line;
	while (std::getline(std::cin, line)) {
		std::vector<double> tokens = tokenize(line);
		if (tokens.size() > 1) {
			Coords coords = {
				tokens[0],
				tokens[1],
				tokens[2],
				tokens[3]
			};
			double p = tokens[4];
			double result = calculate_distance(coords, p);
			std::cout << std::setprecision(10) << std::fixed << result << '\n';
		}
	}

	return 0;
}