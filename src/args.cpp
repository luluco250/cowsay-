#include "args.hpp"
#include <iterator>
#include <sstream>
#include "utils.hpp"

ProgramArgs handle_args(int argc, char** argv) {
	//std::vector<std::string_view> lines(argv + 1, argv + argc);
	//auto message = join(lines, '\n');

	std::ostringstream oss;

	auto p = argv + 1;
	for (; p < argv + argc - 1; ++p)
		oss << *p << ' ';
	
	if (p < argv + argc)
		oss << *p;

	return {
		.message = oss.str()
	};
}