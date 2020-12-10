#include "pch.h"
#include "../../CJsonParser.h"

TEST(getCurrencyConversionFactor, noInputDefined) {
	CJsonParser parser("EUR");
	EXPECT_EQ(parser.getValues(), "");
}

TEST(getCurrencyConversionFactor, inputDefined) {
	const auto input = "{\
		\"success\":true,\
		\"timestamp\" : 1607599745,\
		\"base\" : \"EUR\",\
		\"date\" : \"2020-12-10\",\
		\"rates\" : {\
		\"USD\":1.209183\
	}\
	}";
	CJsonParser parser(input);
	EXPECT_EQ(parser.getValues(), input);
}

TEST(getCurrencyConversionFactor, inputDefinedWithDelay) {
	const auto input = "{\
		\"success\":true,\
		\"timestamp\" : 1607599745,\
		\"base\" : \"EUR\",\
		\"date\" : \"2020-12-10\",\
		\"rates\" : {\
		\"USD\":1.209183\
	}\
	}";
	CJsonParser parser;
	parser.setInput(input);
	EXPECT_EQ(parser.getValues(), input);
}