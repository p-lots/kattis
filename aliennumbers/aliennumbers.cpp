#include <cmath>
#include <iostream>
#include <string>

std::string make_target(std::string, std::string, std::string);

int main(int argc, char *argv[])
{
	std::string alien_number, source_language, target_language;
	int case_counter = 0, num_cases;

	std::cin >> num_cases;

	while (case_counter < num_cases) {
		std::cin >> alien_number >> source_language >> target_language;

		std::string result = make_target(alien_number, source_language, target_language);
		
		std::cout << "Case #" << case_counter + 1 << ": " << result << '\n';
		case_counter++;
	}

	return 0;
}

std::string make_target(std::string alien_number, std::string source_language,
	std::string target_language)
{
	unsigned base = source_language.length();
	unsigned alien_num_in_dec = 0;
	unsigned degree = alien_number.length() - 1;
	for (char c : alien_number) {
		auto place = source_language.find(c);
		alien_num_in_dec += (pow(base, degree--) * place);
	}
	
	std::string ret;
	base = target_language.length();
	int place = 0;
	degree = static_cast<int>(log10(alien_num_in_dec) / log10(base));

	while (alien_num_in_dec > 0) {
		place = alien_num_in_dec / pow(base, degree);
		ret += target_language[place];
		alien_num_in_dec -= (pow(base, degree) * place);
		if (degree > 0 && alien_num_in_dec == 0) {
			while (degree-- > 0) {
				ret += target_language[0];
			}
			break;
		}
		degree--;
	}

	return ret;
}