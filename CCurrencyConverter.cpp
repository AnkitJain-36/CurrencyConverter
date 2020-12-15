#include "CCurrencyConverter.h"
#include "CConversionFactorFinder.h"
#include "ErrorStrings.h"

/// <summary>
/// Static function for converting defined amount of money from one courrency to another
/// </summary>
/// <param name="from">currency code of the currency the amount is currently in</param>
/// <param name="to">currency code of the currency the amount is to be converted to</param>
/// <param name="amount">amount of money</param>
/// <param name="err">error string</param>
/// <returns>converted amount</returns>
double CCurrencyConverter::convert(const std::string& from, const std::string& to, const double amount, std::string& err)
{
	auto conversionFactor = CConversionFactorFinder::instance().getConversionFactor(from, to);
	// CURL request failure
	if (-1 == conversionFactor)
	{
		err = Error::SERVER_NOT_RESPONDING;
	}
	// JSON Parse Failure
	else if (0 == conversionFactor)
	{
		err = Error::PARSE_INFO_NOT_FOUND;
	}
	return amount * conversionFactor;
}
