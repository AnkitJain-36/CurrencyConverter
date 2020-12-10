#include "CCurrencyConverter.h"
#include "CRestUsingCurl.h"
double CCurrencyConverter::convert(std::string from, std::string to, double amount)
{
	CRestUsingCurl restObj(from, to);
	return 0.0;
}
