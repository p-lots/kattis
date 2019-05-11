#include <numeric>
#include <iostream>
#include <string>

int get_rot_val(std::string str)
{
	return std::accumulate(str.begin(), str.end(), 0, [](int n, char c) {
		return n + static_cast<int>(c - 'A');
	});
}

std::string get_rot(std::string str, int rot_val)
{
	std::string ret = "";
	for (const char &c : str) {
		ret.push_back(static_cast<char>((static_cast<int>(c - 'A') + rot_val) % 26 + 'A'));
	}
	return ret;
}

std::string merge(std::string s1, std::string s2)
{
	std::string ret = "";
	for (unsigned i = 0; i < s1.length(); i++) {
		ret.push_back((static_cast<char>(static_cast<int>(s1[i] - 'A') + static_cast<int>(s2[i] - 'A'))) % 26 + 'A');
	}
	return ret;
}

int main(int argc, char *argv[])
{
	std::string input;
	std::getline(std::cin, input);
	auto first_half = input.substr(0, input.length() / 2);
	auto second_half = input.substr(input.length() / 2);
	auto first_rot_val = get_rot_val(first_half);
	auto second_rot_val = get_rot_val(second_half);
	auto first_rot = get_rot(first_half, first_rot_val);
	auto second_rot = get_rot(second_half, second_rot_val);
	auto result = merge(first_rot, second_rot);
	std::cout << result << '\n';
	return 0;
}