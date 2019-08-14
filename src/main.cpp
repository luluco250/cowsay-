#include "main.hpp"
#include <iostream>
#include <iterator>
#include <optional>
#include "args.hpp"
#include "cow.hpp"
#include "utils.hpp"

using std::cout;
using std::cin;

template<class T>
using Opt = std::optional<T>;

int main(int argc, char** argv) {
	auto args = handle_args(argc, argv);
	Opt<std::string> message;

	if (args.has_message()) {
		message = args.message;
	} else {
		std::ostringstream oss;
		std::string str;
		while (std::getline(cin, str))
			oss << str;
		
		message = oss.str();
	}

	cout << default_cow.say(*message);
}