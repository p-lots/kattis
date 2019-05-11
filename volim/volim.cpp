#include <iostream>

int main()
{
	const int total_time = 210;
	int current_player, num_questions;
	std::cin >> current_player >> num_questions;
	int seconds_elapsed = 0;
	while (num_questions--) {
		int time_to_answer;
		char result;
		std::cin >> time_to_answer >> result;
		seconds_elapsed += time_to_answer;
		if (seconds_elapsed >= total_time) break;
		if (result == 'T') current_player++;
		if (current_player > 8) current_player = 1;
	}
	std::cout << current_player;
	return 0;
}