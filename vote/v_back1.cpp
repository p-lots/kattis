#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
	int cases;
	std::cin >> cases;
	while (cases--) {
		int num_candidates;
		std::cin >> num_candidates;
		std::vector<int> candidate_votes;
		int max = 0, current_candidate = 1, winning_candidate = 0;
		bool tie = false;
		while (num_candidates--) {
			int temp;
			std::cin >> temp;
			candidate_votes.push_back(temp);
			std::cout << "pushed back " << temp << '\n';
			if (temp == max) {
				tie = true;
				std::cout << "tie = true\n";
			}
			else {
				tie = false;
				std::cout << "tie = false\n";
			}
			if (temp > max) {
				std::cout << "temp > max\n";
				max = temp;
				std::cout << "max: " << max << '\n';
				winning_candidate = current_candidate;
				std::cout << "winning_candidate: " << winning_candidate << '\n';
			}
			current_candidate++;
		}
		if (tie) {
			std::cout << "no winner\n";
			std::cout << std::string(15, '=');
			std::cout << '\n' << '\n';
			continue;
		}
		int total = std::accumulate(candidate_votes.begin(), candidate_votes.end(), 0);
		std::cout << "total: " << total << '\n';
		//int majority = (total % 2 == 1 ? total / 2 + 1 : total / 2);
		int majority = total / 2;
		std::cout << "majority: " << majority << '\n';
		//unsigned winning_candidate =
		//	std::distance(candidate_votes.begin(),
		//		std::max_element(candidate_votes.begin(), candidate_votes.end())) + 1;
		unsigned winning_candidate_votes =
			*std::max_element(candidate_votes.begin(), candidate_votes.end());
		std::cout << "winning_candidate_votes: " << winning_candidate_votes << '\n';
		if (winning_candidate_votes > majority) {
			std::cout << "majority winner " << winning_candidate;
		}
		else if (winning_candidate_votes <= majority) {
			std::cout << "minority winner " << winning_candidate;
		}
		std::cout << '\n';
		std::cout << std::string(15, '=');
		std::cout << '\n' << '\n';
	}
	return 0;
}
