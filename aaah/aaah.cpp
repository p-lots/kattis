#include <iostream>
#include <string>

int count_a(std::string line)
{
	int ret = 0;
	std::string::size_type start = 0, end;
	while ((end = line.find('a', start)) != std::string::npos) {
		ret++;
		start = end + 1;
	}
	return ret;
}

int main(int argc, char *argv[])
{
	std::string temp;
	bool first_time = true;
	int actual = 0, expected = 0;

	while (std::getline(std::cin, temp)) {
		if (first_time) {
			actual = count_a(temp);
			first_time = false;
		}
		else {
			expected = count_a(temp);
		}
	}

	std::cout << (actual >= expected ? "go" : "no");
	return 0;
}