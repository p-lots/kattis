#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void make_ans(std::vector<char> &, std::vector<char>, int);

int main(int argc, char *argv[])
{
	int total_questions;
	std::string line;
	std::getline(std::cin, line);
	total_questions = std::stoi(line);
	std::vector<char> adrian, bruno, goran;
	make_ans(adrian, { 'A', 'B', 'C' }, total_questions);
	make_ans(bruno, { 'B', 'A', 'B', 'C' }, total_questions);
	make_ans(goran, { 'C', 'C', 'A', 'A', 'B', 'B' }, total_questions);
	std::string answers;
	std::getline(std::cin, answers);
	int adrian_total = 0, bruno_total = 0, goran_total = 0;
	for (unsigned i = 0; i < total_questions; i++) {
		if (answers[i] == adrian[i]) {
			adrian_total++;
		}
		if (answers[i] == bruno[i]) {
			bruno_total++;
		}
		if (answers[i] == goran[i]) {
			goran_total++;
		}
	}
	int max_of_ans = std::max(adrian_total, std::max(bruno_total, goran_total));
	std::cout << max_of_ans << '\n';
	if (max_of_ans == adrian_total) {
		std::cout << "Adrian\n";
	}
	if (max_of_ans == bruno_total) {
		std::cout << "Bruno\n";
	}
	if (max_of_ans == goran_total) {
		std::cout << "Goran\n";
	}
	return 0;
}

void make_ans(std::vector<char> &person,
	std::vector<char> answers, int total_questions)
{
	while (person.size() < total_questions) {
		person.insert(person.end(), answers.begin(), answers.end());
	}
}