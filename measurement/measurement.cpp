#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::vector<long double> > lookup_table = {
	//              thou           inch           foot           yard           chain          furlong        mile           league
	/* thou    */ {           1.0,        1000.0,       12000.0,       36000.0,      792000.0,     7920000.0,    63360000.0,   190080000.0 },
	/* inch    */ {         0.001,           1.0,          12.0,          36.0,         792.0,        7920.0,       63360.0,      190080.0 },
	/* foot    */ { 0.00008333333, 0.08333333333,           1.0,           3.0,          66.0,         660.0,        5280.0,       15840.0 },
	/* yard    */ { 0.00002777777, 0.02777777777, 0.33333333333,           1.0,          22.0,         220.0,        1760.0,        5280.0 },
	/* chain   */ { 0.00000126262, 0.00126262626, 0.01515151515, 0.04545454545,           1.0,          10.0,          80.0,         240.0 },
	/* furlong */ {    1.26262e-7, 0.00012626262, 0.00151515151, 0.00454545454,           0.1,           1.0,           8.0,          24.0 },
	/* mile    */ {   1.578275e-8, 0.00001578282, 0.00018939393, 0.00056818181,        0.0125,         0.125,           1.0,           3.0 },
	/* league  */ { 5.26091667e-9, 0.00000526094, 0.00006313131, 0.00018939393, 0.00416666666, 0.04166666666, 0.33333333333,           1.0 }
};

std::map<std::string, unsigned> long_name_lookup = {
	{ "thou",    0 },
	{ "inch",    1 },
	{ "foot",    2 },
	{ "yard",    3 },
	{ "chain",   4 },
	{ "furlong", 5 },
	{ "mile",    6 },
	{ "league",  7 }
};

std::map<std::string, unsigned> short_name_lookup = {
	{ "th",  0 },
	{ "in",  1 },
	{ "ft",  2 },
	{ "yd",  3 },
	{ "ch",  4 },
	{ "fur", 5 },
	{ "mi",  6 },
	{ "lea", 7 }
};

std::vector<std::string> tokenize(std::string line)
{
	std::vector<std::string> ret;
	std::stringstream ss(line);
	std::string temp;
	while (std::getline(ss, temp, ' '))
		ret.push_back(temp);
	return ret;
}

int main()
{
	std::string line;
	while (std::getline(std::cin, line)) {
		auto tokens = tokenize(line);
		auto units = std::stold(tokens.at(0));
		auto from_units = tokens.at(1);
		auto to_units = tokens.at(3);
		unsigned from_idx = 0, to_idx = 0;
		if (from_units.length() > 3) {
			from_idx = long_name_lookup.at(from_units);
		}
		else {
			from_idx = short_name_lookup.at(from_units);
		}
		if (to_units.length() > 3) {
			to_idx = long_name_lookup.at(to_units);
		}
		else {
			to_idx = short_name_lookup.at(to_units);
		}
		auto result = units * lookup_table[to_idx][from_idx];
		std::cout << std::fixed << std::setprecision(9) << result << '\n';
	}
	return 0;
}