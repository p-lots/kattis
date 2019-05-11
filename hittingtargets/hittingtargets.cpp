#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

typedef struct {
	int x;
	int y;
} Point;

typedef struct {
	Point bottomleft;
	Point topright;
} Rectangle;

typedef struct {
	Point center;
	int r;
} Circle;

std::vector<std::string> tokenize(std::string line) {
	std::stringstream ss(line);
	std::string temp;
	std::vector<std::string> ret;
	while (std::getline(ss, temp, ' ')) {
		ret.push_back(temp);
	}
	return ret;
}

double distance(Point p1, Point p2) {
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

bool hit_rect(Rectangle rect, Point shot)
{
	return (shot.x <= rect.topright.x) && (shot.y <= rect.topright.y)
		&& (shot.x >= rect.bottomleft.x) && (shot.y >= rect.bottomleft.y);
}

bool hit_circ(Circle circ, Point shot)
{
	return distance(shot, circ.center) <= static_cast<double>(circ.r);
}

int main(int argc, char *argv[])
{
	std::vector<Point> shots_vec;
	std::vector<Rectangle> rect_vec;
	std::vector<Circle> circ_vec;
	std::string temp;
	bool first_time = true, start_reading_shots = false;
	int num_shapes = 0, num_shots = 0;
	while (std::getline(std::cin, temp)) {
		if (first_time) {
			num_shapes = std::stoi(temp);
			first_time = false;
		}
		else {
			if (num_shapes > 0) {
				Rectangle rect;
				Circle circ;

				if (temp[0] == 'r') {
					std::vector<std::string> tokens = tokenize(temp.substr(10));
					rect.bottomleft.x = std::stoi(tokens[0]);
					rect.bottomleft.y = std::stoi(tokens[1]);
					rect.topright.x = std::stoi(tokens[2]);
					rect.topright.y = std::stoi(tokens[3]);
					rect_vec.push_back(rect);
				}
				else if (temp[0] == 'c') {
					std::vector<std::string> tokens = tokenize(temp.substr(7));
					circ.center.x = std::stoi(tokens[0]);
					circ.center.y = std::stoi(tokens[1]);
					circ.r = std::stoi(tokens[2]);
					circ_vec.push_back(circ);
				}

				if (num_shapes > 1) {
					num_shapes--;
				}
				else if (num_shapes == 1) {
					start_reading_shots = true;
					num_shapes--;
				}
			}
			else if (start_reading_shots) {
				num_shots = std::stoi(temp);
				start_reading_shots = false;
			}
			else { // start reading shots
				Point point_temp;
				std::vector<std::string> tokens = tokenize(temp);
				point_temp.x = std::stoi(tokens[0]);
				point_temp.y = std::stoi(tokens[1]);
				shots_vec.push_back(point_temp);
			}
		}
	}

	int hit_shots_count = 0;

	for (Point shot : shots_vec) {
		for (Rectangle rect : rect_vec) {
			if (hit_rect(rect, shot)) {
				hit_shots_count++;
			}
		}
		for (Circle circ : circ_vec) {
			if (hit_circ(circ, shot)) {
				hit_shots_count++;
			}
		}
		std::cout << hit_shots_count << '\n';
		hit_shots_count = 0;
	}

	return 0;
}