#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
	int n, p, q;
	std::cin >> n >> p >> q;
	std::vector<bool> turns(p + q + 1, true);
	bool opp_turn = false;
	int counter = 0;
	for (auto it = turns.begin(); it != turns.end(); it++) {
		if (counter % n == 0 && it != turns.begin()) {
			opp_turn = !opp_turn;
		}
		if (opp_turn) {
			*it = false;
		}
		counter++;
	}
	std::cout << (turns.back() ? "paul" : "opponent");
	return 0;
}