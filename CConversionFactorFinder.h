#include <string>
#include "curl/curl.h"
#include "CJsonCurrencyParser.h"

#pragma once
/// <summary>
/// Uses cURL and json parser to get conversion factor
/// </summary>
class CConversionFactorFinder
{
public:
    /// <summary>
    /// Constructor
    /// </summary>
    CConversionFactorFinder() = default;

    /// <summary>
    /// Destructor
    /// </summary>
    virtual ~CConversionFactorFinder() = default;

    /// <summary>
    /// Get conversion factor for converting a currency from a defined currency to another
    /// </summary>
    /// <param name="from">Base currency code</param>
    /// <param name="to">Target currency code</param>
    /// <returns>Conversion Factor</returns>
    double getConversionFactor(const std::string& from, const std::string& to);

    /// <summary>
    /// Json parser
    /// </summary>
    CJsonCurrencyParser m_jsonReader;
};

