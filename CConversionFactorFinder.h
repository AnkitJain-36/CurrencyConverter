#include <string>
#include "curl/curl.h"
#include "rest_curl/CCurlProxy.h"
#include "json_parser/CJsonCurrencyParser.h"
#include "memory"

#pragma once
/// <summary>
/// Uses cURL and json parser to get conversion factor
/// </summary>
class CConversionFactorFinder
{
public:
    /// <summary>
    /// Returns singleton instance
    /// </summary>
    /// <returns>Singleton instance</returns>
    static CConversionFactorFinder& instance();

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
    std::shared_ptr<CJsonCurrencyParser> m_jsonReader;

    /// <summary>
    /// Curl Proxy
    /// </summary>
    CCurlProxy* m_curlProxy;

private:
    /// <summary>
    /// Constructor
    /// </summary>
    CConversionFactorFinder();

    /// <summary>
    /// Destructor
    /// </summary>
    virtual ~CConversionFactorFinder() = default;

    // Prevent copy comstructor
    CConversionFactorFinder (const CConversionFactorFinder&) = delete;
    // Prevent '=' to create object copy
    CConversionFactorFinder& operator = (const CConversionFactorFinder&) = delete;
};

