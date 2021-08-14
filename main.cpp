#include "Calculator.h"
#include <iostream>


int main() {

	// Thread-safe singleton Calculator instance
	const auto& calc = Calculator::instance();
	
	// Print monthly wage expanses (wage plus bonus)
	std::cout << calc.month_wage_expenses() << std::endl;

}

