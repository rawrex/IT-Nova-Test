#ifndef DATAFILE_H
#define DATAFILE_H

#include <vector>
#include <fstream>
#include <sstream>
#include <memory>
#include <string>
#include <utility>

#include <iostream>

// Auxilary base class used to factor out common functionality
// For classes (currently Settings and Staff) that read out from text files

class DataFile {
protected:
	std::shared_ptr<std::vector<std::string>> lines;

public:
	// Constructor
	DataFile(const std::string& filename) : lines(new std::vector<std::string>()) {
		std::ifstream infile(filename);	
		// If the data file is not present
		if (!infile.is_open()) {
			const std::string message = "File not found: " + filename;
			throw std::runtime_error(message);
		}
		// Read lines
		std::string line;
		while (getline(infile, line))
			lines->push_back(line);
	}
};

#endif
