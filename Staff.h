#ifndef STAFF_H
#define STAFF_H

#define STAFF_FILENAME "Data/staff.txt"

#include <iostream>
#include <vector>
#include <memory>
#include <utility>
#include <numeric>
#include "DataFile.h"
#include "Account.h"
#include "Utility.h"
#include "Factory.h"

class Account;
class DataFile;

// Auxilary container-like class used to group all of the employees
// Employees are fetched from a text file specified in the STAFF_FILENAME
// Provides iterators for range operation on the whole container

class Staff: public DataFile {
	std::vector<std::shared_ptr<Account>> employees;

public:
	Staff() : DataFile(STAFF_FILENAME), employees() {
		for (const std::string& line : *lines) {
			std::pair<std::string, std::string> data = extract_data(line);
			employees.emplace_back(factory(data.first, data.second));
		}
	}
	void print() const {
		for (auto ptr : employees)
			std::cout << ptr->total() << std::endl;
	}
	std::vector<std::shared_ptr<Account>>::iterator begin() {
		return employees.begin();
	}
	std::vector<std::shared_ptr<Account>>::iterator end() {
		return employees.end();
	}
	std::vector<std::shared_ptr<Account>>::const_iterator cbegin() const {
		return employees.cbegin();
	}
	std::vector<std::shared_ptr<Account>>::const_iterator cend() const {
		return employees.cend();
	}
};

#endif
