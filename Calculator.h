#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Staff.h"
#include "Account.h"
#include "Singleton.h"

class Account;
class Staff;
template <typename T> class Singleton;

// Used to operate on a Staff instance (default constructed from a text file)

class Calculator: public Singleton<Calculator> {
	Staff staff;
public:
	// The token is defined in the Singleton.h
	// And is used to avoid befriending needed classes
	Calculator(token) : staff() {}
	double n_months_wage_expense(const unsigned& n = 1) const {
		return n * std::accumulate(staff.cbegin(), staff.cend(), 0,
			[](unsigned current, const std::shared_ptr<Account> acc_ptr) 
			{ return current + acc_ptr->total(); });
	}
	double month_wage_expenses(const unsigned& n = 1) const {
		return this->n_months_wage_expense();
	}
};

#endif
