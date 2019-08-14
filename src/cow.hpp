#ifndef COWSAYPP_COW_HPP
#define COWSAYPP_COW_HPP

#include <string_view>
#include <string>

struct Cow {
	const std::string_view content;

	std::string say(const std::string_view text) const;
	std::string think(const std::string_view text) const;
};

extern const Cow default_cow;

#endif /* Include guard. */