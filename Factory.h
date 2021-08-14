#ifndef FACTORY_H
#define FACTORY_H

#include "Account.h"
#include "Professor.h"
#include "Assistant.h"

// Used to construct an instance of a class from the Account inheritance tree 
// Possibly flawed design approach due to use of string labels
// And due to the need to explicitly add new clauses for these labels
//
Account* factory(const std::string& job, const std::string& name) {
	if (job == "Professor")
		return Professor(name).clone();
	if (job == "Assistant")
		return Assistant(name).clone();
	throw std::runtime_error("Unknown job type");
}

#endif
