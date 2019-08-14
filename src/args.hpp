#ifndef COWSAYPP_ARGS_HPP
#define COWSAYPP_ARGS_HPP

#include <string>
#include <string_view>
#include <vector>

struct ProgramArgs {
	std::string message;
	//std::vector<std::string_view> lines;

	inline bool has_message() const {
		return this->message[0] != '\0';
	}
};

ProgramArgs handle_args(int argc, char** argv);

#endif /* Include guard. */