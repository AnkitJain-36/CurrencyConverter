#pragma once
#include "CJsonParser.h"

/// <summary>
/// parses string input in Json format to get currency converstion factor for defined currency
/// </summary>
class CJsonCurrencyParser :
    public CJsonParser
{
public:
    /// <summary>
    /// Constructor
    /// </summary>
    CJsonCurrencyParser();

    /// <summary>
    /// Virtual destructor
    /// </summary>
    virtual ~CJsonCurrencyParser() = default;

    /// <summary>
    /// Returns conversion factor for converting base currency to defined target currency
    /// </summary>
    /// <param name="currencyCode">Currency code of target currency</param>
    /// <returns>Conversion factor</returns>
    virtual double getCurrencyConversionFactor(const std::string& currencyCode);
};

