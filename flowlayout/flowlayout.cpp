#include <iostream>
#include <vector>

typedef struct {
	int width;
	int height;
} Object;

int main(int argc, char *argv[])
{
	int max_width;
	while (std::cin >> max_width) {
		if (max_width == 0) {
			break;
		}
		int obj_width, obj_height;
		std::vector<Object> objects;
		while (std::cin >> obj_width >> obj_height) {
			if (obj_width == -1 && obj_height == -1) {
				break;
			}
			Object temp = { obj_width, obj_height };
			objects.push_back(temp);
		}
		int final_width = 0, final_height = 0, curr_row_width = 0, curr_row_max_height = 0;
		for (const auto o : objects) {
			if (curr_row_width + o.width > max_width) {
				final_height += curr_row_max_height;
				curr_row_width = o.width;
				curr_row_max_height = o.height;
			}
			else {
				curr_row_width += o.width;
				curr_row_max_height = std::max(o.height, curr_row_max_height);
			}
			final_width = std::max(final_width, curr_row_width);
		}
		final_height += curr_row_max_height;
		std::cout << final_width << " x " << final_height << '\n';
	}
	return 0;
}