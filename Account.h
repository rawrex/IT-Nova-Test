#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include "Settings.h"

// Text file with the needed wage settings
#define SETTINGS_FILENAME "Data/settings.txt"

class Account {
protected:
	// Account's user name 
	std::string name;
	// Wage settings, prefetched from a file 
	static Settings settings;

public:
	// Constructors
	Account(const std::string& n) : name(n) {}

	// Copy control
	virtual ~Account() {}

	// Public utility functions
	virtual Account* clone() const& = 0;
	virtual Account* clone() && = 0;

	// Public wage realted computations
	virtual double wage() const = 0;
	virtual double total() const = 0;
	double bonus() const {
		return settings.get("Bonus");
	}
};

// Settings are shared by all instances of the Account
Settings Account::settings = Settings();
#endif
