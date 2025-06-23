#ifndef APP_H
#define APP_H

#include "../Vector/Vector.h"
#include "../Input/Input.h"
#include "Fractions.h"
#include <iostream>
#include <format>

class App {
public:
	Fraction enterFractionUntilValidUseCase();
	Vector<Fraction> enterMultipleFractionsUseCase();
	Fraction computeFractionsSumUseCase(const Vector<Fraction>& fractions);
	void printSumReportUseCase(const Fraction& f);
};

#include "App.cpp"
#endif