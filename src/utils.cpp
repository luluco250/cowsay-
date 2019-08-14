#include "utils.hpp"
#include <vector>
#include <string_view>

std::vector<std::string_view> split(std::string_view text, char delim) {
	std::vector<std::string_view> s;

	size_t start = 0, length = 0;
	for (const auto c : text) {
		++length;
		if (c == delim) {
			s.push_back(text.substr(start, length - 1));

			start += length;
			length = 0;

			continue;
		}
	}

	s.push_back(text.substr(start));

	return s;
}

std::vector<std::string_view> split(
	std::string_view text,
	std::string_view delim
) {
	std::vector<std::string_view> s;
	auto text_size = text.size();
	auto delim_size = delim.size();

	size_t start = 0, length = 0;

	while (start + length < text_size - delim_size) {
		auto sub = text.substr(start + length, delim_size);
		if (sub == delim) {
			auto extracted = text.substr(start, length);
			s.push_back(extracted);
			start += length + delim_size;
			length = 0;
			continue;
		}

		++length;
	}

	s.push_back(text.substr(start));

	return s;
}

/*std::string_view replace(
	const std::string_view str,
	const std::string_view to_find,
	const std::string_view to_replace
) {
	std::ostringstream oss;

	std::string_view::size_type last = 0;
	for (auto i = str.find(to_find); i < str.npos; i = str.find(to_find)) {
		oss << str.substr(last, i - 1) << to_replace;
		i += to_find.size();
		last = i;
	}

	oss << str.substr(last);

	return oss.str();
}*/