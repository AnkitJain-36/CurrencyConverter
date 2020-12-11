#include "CJsonCurrencyParser.h"

/// <summary>
/// Constructor
/// </summary>
CJsonCurrencyParser::CJsonCurrencyParser()
{
	//do nothing
}

/// <summary>
/// Returns conversion factor for converting base currency to defined target currency
/// </summary>
/// <param name="currencyCode">Currency code of target currency</param>
/// <returns>Conversion factor</returns>
double CJsonCurrencyParser::getCurrencyConversionFactor(const std::string& currencyCode)
{
	// add checks for these values?
	return m_root["rates"][currencyCode].asDouble();
}
