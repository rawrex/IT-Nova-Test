#ifndef UTILITY_H
#define UTILITY_H

#define DELIMITER ':'

#include <utility>
#include <string>

// Used to split a string using a delimiter
// Returns a pair of strings of the contents:
// <before_the_delimiter, after_the_delimiter>

std::pair<std::string, std::string>
extract_data(const std::string& line, const char& delimiter = DELIMITER) {
	std::string a = line.substr(0, line.find(delimiter));
	std::string b = line.substr(a.length()+1);
	return {a,b};
}
#endif
