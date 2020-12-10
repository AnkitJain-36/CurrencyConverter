#pragma once
#include "CJsonParser.h"

class CJsonCurrencyParser :
    public CJsonParser
{
    std::string m_base;
public:
    CJsonCurrencyParser(const std::string& base);
    CJsonCurrencyParser(const std::string& base, const std::string& input);
    double getCurrencyConversionFactor(const std::string& currencyCode);
};

