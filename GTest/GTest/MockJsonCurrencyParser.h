#pragma once
#include "string"
#include "pch.h"
#include "../../json_parser/CJsonCurrencyParser.h"

class MockJsonCurrencyParser:
	public CJsonCurrencyParser
{
public:
	MOCK_METHOD(double, getCurrencyConversionFactor, (const std::string& currencyCode), (override));
};