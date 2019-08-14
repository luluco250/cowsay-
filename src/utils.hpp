#ifndef COWSAYPP_UTILS_HPP
#define COWSAYPP_UTILS_HPP

#include <vector>
#include <string>
#include <string_view>
#include <sstream>

std::vector<std::string_view> split(std::string_view text, char delim);
std::vector<std::string_view> split(
	std::string_view text,
	std::string_view delim
);

template<class Collection, class Sep>
std::string join(
	//const std::vector<std::string_view>& collection,
	const Collection& collection,
	const Sep& sep
) {
	std::stringstream oss;

	auto p = collection.begin();
	for (; p < collection.end() - 1; ++p)
		oss << *p << sep;
	
	oss << *p;
	return oss.str();
}

/*std::string replace(
	const std::string_view str,
	const std::string_view to_find,
	const std::string_view to_replace
);*/

#endif /* Include guard. */