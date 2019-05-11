#include <algorithm>
#include <iostream>

int main(int argc, char *argv[])
{
	int s_0, s_1, r_0, r_1;
	while (std::cin >> s_0 >> s_1 >> r_0 >> r_1) {
		if ((s_0 == 0 && s_1 == 0) && (r_0 == 0 && r_1 == 0)) {
			break;
		}
		if (s_1 > s_0) {
			std::swap(s_0, s_1);
		}
		if (r_1 > r_0) {
			std::swap(r_0, r_1);
		}
		int player_1 = s_0 * 10 + s_1;
		int player_2 = r_0 * 10 + r_1;
		if (player_1 == player_2) {
			std::cout << "Tie.\n";
		}
		else {
			int winner = 0;
			if (player_1 == 21 || player_2 == 21) {
				winner = player_1 == 21 ? 1 : 2;
			}
			else if (s_0 == s_1 && r_0 == r_1) {
				winner = player_1 > player_2 ? 1 : 2;
			}
			else if (s_0 == s_1) {
				winner = 1;
			}
			else if (r_0 == r_1) {
				winner = 2;
			}
			std::cout << "Player " << winner << " wins.\n";
		}
	}
	return 0;
}