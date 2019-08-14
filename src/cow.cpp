#include "cow.hpp"
#include <sstream>
#include <algorithm>
#include <regex>
#include <iostream>
#include "utils.hpp"

size_t get_width(const std::vector<std::string_view> message) {
	size_t width = 0;

	for (const auto line : message)
		width = std::max(width, line.size());

	return width;
}

void print_line(
	std::ostream& os,
	std::string_view line,
	size_t width,
	char left,
	char right
) {
	os << left << ' ' << line;

	for (size_t i = 0; i < width - line.size() + 1; ++i)
		os << ' ';
	
	os << right << '\n';
}

void print_border(std::ostream& os, size_t width, char c) {
	os << ' ';
	
	for (size_t i = 0; i < width + 2; ++i)
		os << c;

	os << '\n';
}

void print_cow(
	std::ostream& os,
	const std::string_view content,
	char bubble_line
) {
	auto lines = split(content, '\n');
	size_t i = 0;

	for (const auto line : lines) {
		switch (i) {
			case 0:
				os << '\t' << bubble_line << "   ";
				break;
			case 1:
				os << "\t " << bubble_line << "  ";
				break;
			default:
				os << "\t    ";
				break;
		}

		os << line << '\n';		
		++i;
	}
}

const std::regex regex_tab("\\t");

std::string Cow::say(const std::string_view raw_text) const {
	const auto text = std::regex_replace(
		std::string(raw_text),
		regex_tab,
		"        "
	);

	auto lines = split(text, '\n');
	auto line_count = lines.size();
	auto width = get_width(lines);
	std::ostringstream oss;	

	print_border(oss, width, '_');
	
	if (line_count == 1) {
		print_line(oss, lines[0], width, '<', '>');
	} else if (line_count > 1) {
		print_line(oss, lines[0], width, '/', '\\');

		size_t i;
		for (i = 1; i <= line_count - 2; ++i)
			print_line(oss, lines[i], width, '|', '|');

		print_line(oss, lines[i], width, '\\', '/');
	}

	print_border(oss, width, '-');
	print_cow(oss, this->content, '\\');
	
	return oss.str();
}

std::string Cow::think(const std::string_view text) const {
	auto lines = split(text, '\n');
	auto line_count = lines.size();
	auto width = get_width(lines);
	std::ostringstream oss;

	print_border(oss, width, '_');

	for (const auto line : lines)
		print_line(oss, line, width, '(', ')');
	
	print_border(oss, width, '-');
	print_cow(oss, this->content, 'o');

	return oss.str();
}

const Cow default_cow = {
	.content = 1 + R"(
^__^
(oo)\_______
(__)\       )\/\
	||----w |
	||     ||)"
};