#include "json/json.h"
#pragma once

/// <summary>
/// Uses JsonCpp library for parsing json format string(s)
/// Recommended usage: Inherit the class to use m_root (parsed json value object)
/// </summary>
class CJsonParser
{
protected:
	/// <summary>
	/// root variable of parsed json input
	/// </summary>
	Json::Value m_root;
public:
	/// <summary>
	/// Constructor (default)
	/// </summary>
	CJsonParser() = default;

	/// <summary>
	/// Parameterized constructor with json string defined
	/// </summary>
	/// <param name="input">input string in Json format</param>
	CJsonParser(const std::string& input);

	/// <summary>
	/// Virtual Destructor
	/// </summary>
	virtual ~CJsonParser() {}

	/// <summary>
	/// Defines the input string
	/// </summary>
	/// <param name="input">input string in Json format</param>
	void setInput(const std::string& input);

	/// <summary>
	/// Returns the input string in JSon format
	/// </summary>
	/// <returns>input string in JSon format</returns>
	std::string getValues();
};

