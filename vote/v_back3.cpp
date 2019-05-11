#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <set>
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
		while (num_candidates--) {
			int temp;
			std::cin >> temp;
			candidate_votes.push_back(temp);
			if (temp > max) {
				max = temp;
				winning_candidate = current_candidate;
			}
			current_candidate++;
		}
		std::set<int> vote_set(candidate_votes.begin(), candidate_votes.end());
		if (vote_set.size() == 1) {
			std::cout << "no winner\n";
			continue;
		}
		int total = std::accumulate(candidate_votes.begin(), candidate_votes.end(), 0);
		int majority = total / 2;
		unsigned winning_candidate_votes =
			*std::max_element(candidate_votes.begin(), candidate_votes.end());
		if (winning_candidate_votes > majority) {
			std::cout << "majority winner " << winning_candidate;
		}
		else if (winning_candidate_votes <= majority) {
			std::cout << "minority winner " << winning_candidate;
		}
		std::cout << '\n';
	}
	return 0;
}