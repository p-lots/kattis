#include <iostream>
#include <vector>

int gcd(int, int);

int main(int argc, char *argv[])
{
	int num_rings;
	std::cin >> num_rings;
	std::vector<int> rings;
	int ring_radius;
	while (std::cin >> ring_radius) {
		rings.push_back(ring_radius);
	}
	int first_ring = rings.front();
	for (auto it = rings.begin() + 1; it != rings.end(); it++) {
		int gc = gcd(first_ring, *it);
		int num = first_ring / gc, denom = *it / gc;
		std::cout << num << "/" << denom << '\n';
	}
	return 0;
}


int gcd(int a, int b)
{
	for (;;) {
		if (a == 0) return b;
		b %= a;
		if (b == 0) return a;
		a %= b;
	}
}