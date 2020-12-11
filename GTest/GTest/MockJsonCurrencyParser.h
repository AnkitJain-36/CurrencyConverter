#pragma once
#include "string"
#include "pch.h"
#include "../../CJsonCurrencyParser.h"

class MockJsonCurrencyParser:
	public CJsonCurrencyParser
{
public:
	MOCK_METHOD(double, getCurrencyConversionFactor, (const std::string& currencyCode), (override));
};