#include "pch.h"
#include "../../CJsonCurrencyParser.h"

TEST(getCurrencyConversionFactor, noInputDefined) {
	CJsonCurrencyParser parser("EUR");
	EXPECT_EQ(parser.getCurrencyConversionFactor("USD"), 0.0);
}

TEST(getCurrencyConversionFactor, inputDefined) {
	CJsonCurrencyParser parser("EUR", "{\
		\"success\":true,\
		\"timestamp\" : 1607599745,\
		\"base\" : \"EUR\",\
		\"date\" : \"2020-12-10\",\
		\"rates\" : {\
		\"USD\":1.209183\
	}\
	}");
	EXPECT_EQ(parser.getCurrencyConversionFactor("USD"), 1.209183);
}

TEST(getCurrencyConversionFactor, inputDefinedWithDelay) {
	CJsonCurrencyParser parser("EUR");
	parser.setInput("{\
		\"success\":true,\
		\"timestamp\" : 1607599745,\
		\"base\" : \"EUR\",\
		\"date\" : \"2020-12-10\",\
		\"rates\" : {\
		\"USD\":1.209183\
	}\
	}");
	EXPECT_EQ(parser.getCurrencyConversionFactor("USD"), 1.209183);
}