#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
	int n, T;
	std::cin >> n >> T;
	std::vector<int> task_times;
	int temp;
	while (std::cin >> temp) {
		task_times.push_back(temp);
	}
	int sum = 0, count = 0;
	for (int d : task_times) {
		sum += d;
		if (sum > T) {
			break;
		}
		count++;
	}
	std::cout << count;
	return 0;
}