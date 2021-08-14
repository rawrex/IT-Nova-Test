#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Account.h"
#include <string>

class Account;

class Professor: public Account {
public:
	// Inherit constructors
	using Account::Account;

	// Get the wage only
	virtual double wage() const override {
		return settings.get("Professor");
	}
	// Get the total income, wage plus bonus
	virtual double total() const override {
		double wage = this->wage();
		double result = wage + wage * this->bonus()/100;
		return result;
	}

	// Get a dynamically allocated copy of the object
	//
	// lvalue ref-qualifier overload
	virtual Professor* clone() const& override {
		return new Professor(*this);
	}
	// rvalue ref-qualifier overload
	virtual Professor* clone() && override {
		return new Professor(std::move(*this));
	}
};

#endif
