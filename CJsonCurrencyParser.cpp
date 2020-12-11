#include "CJsonCurrencyParser.h"


CJsonCurrencyParser::CJsonCurrencyParser()
{
	//do nothing
}

double CJsonCurrencyParser::getCurrencyConversionFactor(const std::string& currencyCode)
{
	// add checks for these values?
	return m_root["rates"][currencyCode].asDouble();
}
