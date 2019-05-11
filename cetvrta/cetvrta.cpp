#include <algorithm>
#include <iostream>

typedef struct {
	int x;
	int y;
} Point;

bool equals(Point, Point);

int main(int argc, char *argv[])
{
	Point a, b, c;
	int counter = 0, temp, temp2;
	while (std::cin >> temp >> temp2) {
		if (counter == 0) {
			a.x = temp;
			a.y = temp2;
		}
		else if (counter == 1) {
			b.x = temp;
			b.y = temp2;
		}
		else {
			c.x = temp;
			c.y = temp2;
		}
		counter++;
	}
	Point topleft, topright, bottomleft, bottomright, output;
	topright.x = std::max(a.x, std::max(b.x, c.x));
	topright.y = std::max(a.y, std::max(b.y, c.y));
	if (!equals(topright, a) && !equals(topright, b) && !equals(topright, c)) {
		output = topright;
	}
	bottomleft.x = std::min(a.x, std::min(b.x, c.x));
	bottomleft.y = std::min(a.y, std::min(b.y, c.y));
	if (!equals(bottomleft, a) && !equals(bottomleft, b) && !equals(bottomleft, c)) {
		output = bottomleft;
	}
	topleft.x = bottomleft.x;
	topleft.y = topright.y;
	if (!equals(topleft, a) && !equals(topleft, b) && !equals(topleft, c)) {
		output = topleft;
	}
	bottomright.x = topright.x;
	bottomright.y = bottomleft.y;
	if (!equals(bottomright, a) && !equals(bottomright, b) && !equals(bottomright, c)) {
		output = bottomright;
	}
	std::cout << output.x << ' ' << output.y << '\n';
	
	return 0;
}

bool equals(Point a, Point b) {
	return (a.x == b.x) && (a.y == b.y);
}
