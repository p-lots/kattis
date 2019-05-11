#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	unsigned m, p, l, e, r, s, n;
	while (std::cin >> m >> p >> l >> e >> r >> s >> n) {
		unsigned total_eggs = m * e;
		unsigned next_l, next_p, next_m;
		for (unsigned i = 0; i < n; i++) {
			next_l = total_eggs;
			next_p = l / r;
			next_m = p / s;
			total_eggs = next_m * e;
			l = next_l;
			p = next_p;
			m = next_m;
		}
		std::cout << m << '\n';
	}
	return 0;
}
