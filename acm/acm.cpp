#include <iostream>
#include <map>
#include <string>

int main(int argc, char *argv[])
{
	std::string right_or_wrong;
	char problem;
	int minutes;
	int score = 0, solved_problems = 0;
	std::map<char, int> problem_wrong_counter;

	while (std::cin >> minutes >> problem >> right_or_wrong) {
		if (minutes == -1) {
			break;
		}
		
		if (!problem_wrong_counter[problem]) {
			if (right_or_wrong == "right") {
				solved_problems++;
				score += minutes;
			}
			else if (right_or_wrong == "wrong") {
				problem_wrong_counter[problem] = 1;
			}
		}
		else {
			if (right_or_wrong == "right") {
				solved_problems++;
				score += minutes + (problem_wrong_counter[problem] * 20);
			}
			else if (right_or_wrong == "wrong") {
				problem_wrong_counter[problem]++;
			}
		}
	}

	std::cout << solved_problems << ' ' << score;

	return 0;
}