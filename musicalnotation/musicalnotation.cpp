#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

typedef struct {
	int note_pos;
	int len;
	int horiz_pos;
} note_t;

std::vector<std::string> tokenize(std::string);

int main(int argc, char *argv[])
{
	std::string line;
	std::getline(std::cin, line);
	int num_notes = std::stoi(line);
	num_notes += num_notes - 1;
	std::getline(std::cin, line);
	auto tokens = tokenize(line);
	std::string lookup = "GFEDCBAgfedcba";
	std::vector<note_t> result;
	int horiz_pos = 3, len = 1;
	//for (const auto t : tokens) {
	for (auto t = tokens.begin(); t != tokens.end(); t++) {
		auto str = *t;
		if (str.length() > 1) len = str[1] - '0';
		else len = 1;
		int no_pos = lookup.find(str[0]);
		note_t temp;
		temp.note_pos = no_pos;
		temp.len = len;
		temp.horiz_pos = horiz_pos;
		result.push_back(temp);
		if (len > 1) num_notes += len - 1;
		horiz_pos += len + 1;
	}
	std::vector<std::string> staff;
	for (unsigned i = 0; i < lookup.length(); i++) {
		std::string pb;
		pb.push_back(lookup[i]);
		pb += ": ";
		if (((((lookup[i] == 'a' || lookup[i] == 'e') || lookup[i] == 'g')
			|| lookup[i] == 'B') || lookup[i] == 'D') || lookup[i] == 'F') {
			pb += std::string(num_notes, '-');
		}
		else pb += std::string(num_notes, ' ');
		staff.push_back(pb);
	}
	for (const auto note : result) {
		staff[note.note_pos][note.horiz_pos] = '*';
		int len = note.len;
		while (len > 1) {
			staff[note.note_pos][note.horiz_pos + len - 1] = '*';
			len--;
		}
	}
	for (const auto l : staff) {
		std::cout << l << '\n';
	}
	return 0;
}

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