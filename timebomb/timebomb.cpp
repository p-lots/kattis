#include <iostream>
#include <map>
#include <string>
#include <vector>

static const std::map<std::string, int> lookup_table = {
	{
	"***" 
	"* *" 
	"* *" 
	"* *" 
	"***", 0},

	{
	"  *" 
	"  *" 
	"  *" 
	"  *" 
	"  *", 1},

	{
	"***" 
	"  *" 
	"***" 
	"*  " 
	"***", 2},

	{
	"***"
	"  *"
	"***"
	"  *"
	"***", 3},

	{
	"* *"
	"* *"
	"***"
	"  *"
	"  *", 4},

	{
	"***"
	"*  "
	"***"
	"  *"
	"***", 5},

	{
	"***"
	"*  "
	"***"
	"* *"
	"***", 6},

	{
	"***"
	"  *"
	"  *"
	"  *"
	"  *", 7},

	{
	"***"
	"* *"
	"***"
	"* *"
	"***", 8},

	{
	"***"
	"* *"
	"***"
	"  *"
	"***", 9}
};

std::string is_safe(int);

int make_int(std::vector<std::string>);

int main(int argc, char *argv[])
{
	std::string temp;
	std::vector<std::string> input_vec;

	while (std::getline(std::cin, temp)) {
		input_vec.push_back(temp);
	}

	int n = make_int(input_vec);

	std::string result = is_safe(n);

	std::cout << result;

	return 0;
}

std::string is_safe(int n)
{
	if (n > 0 && n % 6 == 0) {
		return "BEER!!";
	}
	else {
		return "BOOM!!";
	}
}

int make_int(std::vector<std::string> input)
{
	std::string ret;

	for (unsigned i = 0; i < input[0].length(); i += 4) {
		std::string n;

		for (unsigned j = 0; j < input.size(); j++) {
			n += input[j].substr(i, 3);
		}

		if (lookup_table.count(n) == 0) {
			return -1;
		}
		else {
			ret += std::to_string(lookup_table.at(n));
		}
	}

	return std::stoi(ret);
}