#include "pch.h"
#include "../../CJsonParser.h"

TEST(getValues, noInputDefined) {
	CJsonParser parser("EUR");
	EXPECT_EQ(parser.getValues(), "null\n");
}

TEST(getValues, inputDefined) {
	const auto input = "{\
		\"success\":true,\
		\"timestamp\" : 1607599745,\
		\"base\" : \"EUR\",\
		\"date\" : \"2020-12-10\",\
		\"rates\" : {\
		\"USD\":1.209183\
	}\
	}";

	const auto output = "{\n\t\"base\" : \"EUR\",\n\t\"date\" : \"2020-12-10\",\n\t\"rates\" : \n\t{\n\t\t\"USD\" : 1.2091829999999999\n\t},\n\t\"success\" : true,\n\t\"timestamp\" : 1607599745\n}\n";
	CJsonParser parser(input);
	EXPECT_EQ(parser.getValues(), output);
}

TEST(getValues, inputDefinedWithDelay) {
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
	const auto output = "{\n\t\"base\" : \"EUR\",\n\t\"date\" : \"2020-12-10\",\n\t\"rates\" : \n\t{\n\t\t\"USD\" : 1.2091829999999999\n\t},\n\t\"success\" : true,\n\t\"timestamp\" : 1607599745\n}\n";
	EXPECT_EQ(parser.getValues(), output);
}