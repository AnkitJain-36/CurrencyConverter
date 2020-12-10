#pragma once
#include "CJsonParser.h"

/// <summary>
/// parses string input in Json format to get currency converstion factor for defined currency
/// </summary>
class CJsonCurrencyParser :
    public CJsonParser
{
    /// <summary>
    /// Base currency code
    /// </summary>
    std::string m_base;
public:
    /// <summary>
    /// Constructor
    /// </summary>
    /// <param name="base">Base currency code</param>
    CJsonCurrencyParser(const std::string& base);

    /// <summary>
    /// Constructor
    /// </summary>
    /// <param name="base">Base currency code</param>
    /// <param name="input">Input string for parsin (in Json format)</param>
    CJsonCurrencyParser(const std::string& base, const std::string& input);

    /// <summary>
    /// Returns conversion factor for converting base currency to defined currency
    /// </summary>
    /// <param name="currencyCode">Currency code of target currency</param>
    /// <returns>Conversion factor</returns>
    double getCurrencyConversionFactor(const std::string& currencyCode);
};

