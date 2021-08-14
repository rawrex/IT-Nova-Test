#ifndef SETTINGS_H
#define SETTINGS_H

#define SETTINGS_FILENAME "Data/settings.txt"

#include <unordered_map>
#include <sstream>
#include <utility>
#include "DataFile.h"
#include "Utility.h"

class DataFile;

class Settings: public DataFile {
	// Stores a wage to a staff category relation
	//
	std::unordered_map<std::string, double> wage_table;
public:
	// (Defualt) constructor
	// Populates the wage_table from a text file 
	// specified by SETTINGS_FILENAME
	//
	Settings() : DataFile(SETTINGS_FILENAME), wage_table() {
		for (const std::string& line : *lines) {
			std::pair<std::string, std::string> data = extract_data(line);
			std::string category_name = data.first, number(data.second);
			wage_table[category_name] = stod(number);
		}
	}

	// Fetch a particular category from the wage_table
	//
	double get(const std::string& key) const {
		return wage_table.at(key);
	}
};

#endif
