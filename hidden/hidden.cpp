#include <iostream>
#include <string>

void validate_pass(std::string);

int main(int argc, char *argv[])
{
	std::string temp;

	while (std::getline(std::cin, temp)) {
		validate_pass(temp);
	}

	return 0;
}

void validate_pass(std::string line)
{
	auto space = line.find(' ');
	std::string password = line.substr(0, space), message = line.substr(space + 1);
	
	bool pass = true;
	auto prev_char_pos = message.find(password[0]);
	auto current_char_pos = message.find_first_of(password.substr(1));
	auto pw_len = password.length();
	if (prev_char_pos == std::string::npos
		|| current_char_pos < prev_char_pos) {
		std::cout << "FAIL";
		return;
	}
	
	password.erase(0, 1);

	for (auto i = 0; i < pw_len - 1; i++) {
		if (password.length() > 2) {
			current_char_pos = message.find(password[0], prev_char_pos);
			if (current_char_pos == std::string::npos) {
				pass = false;
				break;
			}
			std::string remaining = password.substr(2);
			char next = password[1];
			auto remaining_pos = message.find_first_of(remaining, current_char_pos + 1);
			auto next_pos = message.find(next, current_char_pos + 1);
			if (remaining_pos < next_pos || remaining_pos == std::string::npos
				|| next_pos == std::string::npos) {
				pass = false;
				break;
			}
		}
		else if (password.length() > 1) {
			current_char_pos = message.find(password[0], prev_char_pos);
			char last = password[1];
			auto last_pos = message.find(last, prev_char_pos);
			if (last_pos < current_char_pos || last_pos == std::string::npos
				|| current_char_pos == std::string::npos) {
				pass = false;
				break;
			}
		}
		else {
			current_char_pos = message.find(password[0], prev_char_pos);
			if (current_char_pos == std::string::npos) {
				pass = false;
				break;
			}
		}

		password.erase(0, 1);
		prev_char_pos = current_char_pos;
	}

	std::cout << (pass ? "PASS" : "FAIL");
}