// Uses JsonCpp library for parsing json format string(s)

#include "json/json.h"

#pragma once
class CJsonParser
{
protected:
	Json::Value m_root;
public:
	CJsonParser();
	CJsonParser(const std::string& input);
	void setInput(const std::string& input);
	std::string getValues();
};

