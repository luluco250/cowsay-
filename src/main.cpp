#include "main.hpp"
#include <iostream>
#include <iterator>
#include <optional>
#include "args.hpp"
#include "cow.hpp"
#include "utils.hpp"

using std::cout;
using std::cin;

int main(int argc, char** argv) {
	auto args = handle_args(argc, argv);

	// Optional because we'll fill it inside the if.
	std::optional<std::string> message;

	if (args.has_message()) {
		message = args.message;
	} else {
		/*
			Read from stdin/pipe.
		*/
		std::ostringstream oss;
		std::string str;

		while (std::getline(cin, str))
			oss << str << '\n';
		
		// Remove extra newline from loop.
		str = oss.str();
		message = str.substr(0, str.size() - 1);
	}

	cout << default_cow.say(*message);
}