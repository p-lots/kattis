#include <algorithm>
#include <iostream>
#include <vector>

typedef struct {
	int start;
	int end;
} duration;

int main(int argc, char *argv[])
{
	int a, b, c;
	std::cin >> a >> b >> c;
	std::vector<duration> truck_durations;
	int s, e, max_end = 0, min_start = 101;
	while (std::cin >> s >> e) {
		duration temp = { s, e };
		max_end = std::max(e, max_end);
		min_start = std::min(s, min_start);
		truck_durations.push_back(temp);
	}
	int time_arr[max_end - min_start];
	for (int i = 0; i < max_end - min_start; i++) {
		time_arr[i] = 0;
	}
	for (const auto d : truck_durations) {
		for (int i = d.start; i < d.end; i++) {
			int idx = i - min_start;
			time_arr[idx]++;
		}
	}
	int sum = 0;
	for (int i = 0; i < max_end - min_start; i++) {
		if (time_arr[i] == 1) {
			sum += a;
		}
		else if (time_arr[i] == 2) {
			sum += b * 2;
		}
		else if (time_arr[i] == 3) {
			sum += c * 3;
		}
	}
	std::cout << sum;
	return 0;
}