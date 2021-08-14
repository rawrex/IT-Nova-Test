#ifndef ASSISTANT_H
#define ASSISTANT_H

#include "Account.h"

class Account; 

class Assistant: public Account {
public:
	// Inherit constructor(s)
	using Account::Account;

	// Get the wage only
	virtual double wage() const override {
		return settings.get("Assistant");
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
	virtual Assistant* clone() const& override {
		return new Assistant(*this);
	}
	// rvalue ref-qualifier overload
	virtual Assistant* clone() && override {
		return new Assistant(std::move(*this));
	}
};

#endif
