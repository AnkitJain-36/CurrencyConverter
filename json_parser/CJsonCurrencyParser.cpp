#include "CJsonCurrencyParser.h"

/// <summary>
/// Returns conversion factor for converting base currency to defined target currency
/// </summary>
/// <param name="currencyCode">Currency code of target currency</param>
/// <returns>Conversion factor</returns>
double CJsonCurrencyParser::getCurrencyConversionFactor(const std::string& currencyCode)
{
	const std::string ratesTag{ "rates" };
	return m_root[ratesTag][currencyCode].asDouble();
}
