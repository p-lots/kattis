#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main(int argc, char *argv[])
{
	int total_rooms, num_booked_rooms;
	std::cin >> total_rooms >> num_booked_rooms;
	if (num_booked_rooms == total_rooms) {
		std::cout << "too late";
		return 0;
	}
	std::vector<bool> booked_rooms(total_rooms, false);
	while (num_booked_rooms--) {
		int room_number;
		std::cin >> room_number;
		booked_rooms[room_number - 1] = true;
	}
	auto it = std::find(booked_rooms.begin(), booked_rooms.end(), false);
	std::cout << std::distance(booked_rooms.begin(), it) + 1;
	return 0;
}
