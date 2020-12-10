#include "CJsonCurrencyParser.h"


CJsonCurrencyParser::CJsonCurrencyParser(const std::string& base) :
	m_base(base)
{
	//do nothing
}

CJsonCurrencyParser::CJsonCurrencyParser(const std::string& base, const std::string& input) :
	CJsonParser(input),
	m_base(base)
{
	// do nothing
}

double CJsonCurrencyParser::getCurrencyConversionFactor(const std::string& currencyCode)
{
	// add checks for these values?
	return m_root["rates"][currencyCode].asDouble();
}
