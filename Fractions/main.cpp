#include "App.h"

int main() {
    App app;
	Vector<Fraction> fractions= app.enterMultipleFractionsUseCase();
	Fraction sum = app.computeFractionsSumUseCase(fractions);
	app.printSumReportUseCase(sum);
    return 0;
}