#include "CCurrencyConverter.h"
#include "CConversionFactorFinder.h"

/// <summary>
/// Static function for converting defined amount of money from one courrency to another
/// </summary>
/// <param name="from">currency code of the currency the amount is currently in</param>
/// <param name="to">currency code of the currency the amount is to be converted to</param>
/// <param name="amount">amount of money</param>
/// <returns>converted amount</returns>
double CCurrencyConverter::convert(const std::string& from, const std::string& to, const double amount)
{
	double conversionFactor = CConversionFactorFinder::instance().getConversionFactor(from, to);
	// CURL request failure
	if (-1 == conversionFactor)
	{
		return -1;
	}
	else
	{
		return amount * conversionFactor;
	}
}
