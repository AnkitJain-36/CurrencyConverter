#include "CCurrencyConverter.h"
#include "CRestUsingCurl.h"

double CCurrencyConverter::convert(const std::string& from, const std::string& to, const double amount)
{
	CRestUsingCurl restObj(from, to);
	double conversionFactor = restObj.getConversionFactor();
	return amount * conversionFactor;
}
