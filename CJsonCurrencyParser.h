#pragma once
#include "CJsonParser.h"

/* Example:
    For base: "EUR"

    Input:
      "success":true,
      "timestamp":1607579961,
      "base":"EUR",
      "date":"2020-12-10",
      "rates":{
        "AED":4.442183,
        "AFN":93.36032,
        "ALL":123.980456,
        "AMD":623.396141,
        "ANG":2.176415,
        "AOA":792.392099,
        "ARS":99.131869,
        "AUD":1.618775,
        ....
      }
*/


class CJsonCurrencyParser :
    public CJsonParser
{
    std::string m_base;
public:
    CJsonCurrencyParser(const std::string& base);
    CJsonCurrencyParser(const std::string& base, const std::string& input);
    double getCurrencyConversionFactor(const std::string& currencyCode);
};

