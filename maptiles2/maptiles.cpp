#include <iostream>
#include <string>
#include <vector>

typedef struct {
	int x;
	int y;
	std::string quadkey;
} Tile;

int main(int argc, char *argv[])
{
	//std::string line;
	//std::cin >> line;
	unsigned size = 2;
	std::vector<Tile> row(size);
	std::vector<std::vector<Tile> > map;
	Tile first = { 0, 0, "0" };
	for (unsigned i = 0; i < size; i++) {
		for (unsigned j = 0; j < size; j++) {
			row[j] = first;
		}
		map.push_back(row);
	}
	map[0][1] = { 1, 0, "1" };
	map[1][0] = { 0, 1, "2" };
	map[1][1] = { 1, 1, "3" };
	std::cout << "map1:\n";
	for (unsigned i = 0; i < size; i++) {
		for (unsigned j = 0; j < size; j++) {
			std::cout << map[i][j].quadkey << ' ';
		}
		std::cout << '\n';
	}
	for (unsigned i = 0; i < size; i++) {
		for (unsigned j = 0; j < size; j++) {
			std::cout << '(' << map[i][j].x << ',' << map[i][j].y << ") ";
		}
		std::cout << '\n';
	}
	unsigned size_doub = 4;
	std::vector<Tile> row2(size_doub);
	std::vector<std::vector<Tile> > map2;
	//for (unsigned i = 0; i < size_doub; i++) {
	//	for (unsigned j = 0; j < size_doub; j++) {
	//		row2[j] = first;
	//	}
	//	map2.push_back(row2);
	//}
	bool alternate = true;
	for (unsigned i = 0; i < size_doub; i++) {
		std::string qk;
		for (unsigned j = 0; j < size_doub; j++) {
			if (i < 2 && j < 2) {
				//row2[j] = map[0][0];
				qk = map[0][0].quadkey;
				qk += std::to_string(j);
				row2[j] = { static_cast<int>(i), static_cast<int>(j), qk };
			}
			else if (!(i < 2) && j < 2) {
				//row2[j] = map[1][0];
				std::string qk = map[1][0].quadkey;
				qk += std::to_string(j);
				row2[j] = { static_cast<int>(i), static_cast<int>(j), qk };
			}
			else if (i < 2 && !(j < 2)) {
				//row2[j] = map[0][1];
				std::string qk = map[0][1].quadkey;
				qk += std::to_string(j);
				row2[j] = { static_cast<int>(i), static_cast<int>(j), qk };
			}
			else {
				//row2[j] = map[1][1];
				std::string qk = map[1][1].quadkey;
				qk += std::to_string(j);
				row2[j] = { static_cast<int>(i), static_cast<int>(j), qk };
			}
		}
		map2.push_back(row2);
	}
	std::cout << "map2:\n";
	for (unsigned i = 0; i < size_doub; i++) {
		for (unsigned j = 0; j < size_doub; j++) {
			std::cout << map2[i][j].quadkey << ' ';
		}
		std::cout << '\n';
	}
	for (unsigned i = 0; i < size_doub; i++) {
		for (unsigned j = 0; j < size_doub; j++) {
			std::cout << '(' << map2[i][j].x << ',' << map2[i][j].y << ") ";
		}
		std::cout << '\n';
	}
	/*
	auto size = std::pow(4, line.length());
	std::vector<Tile> row(size);
	std::vector<std::vector<Tile> > map;
	for (unsigned i = 0; i < size; i++) {
		map.push_back(row);
	}
	*/
	return 0;
}