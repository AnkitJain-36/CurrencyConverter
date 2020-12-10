#pragma once
#include <string>

/// <summary>
/// Currency conversion class
/// </summary>
class CCurrencyConverter
{
public:
	/// <summary>
	/// Static function for converting defined amount of money from one courrency to another
	/// </summary>
	/// <param name="from">currency code of the currency the amount is currently in</param>
	/// <param name="to">currency code of the currency the amount is to be converted to</param>
	/// <param name="amount">amount of money</param>
	/// <returns>converted amount</returns>
	static double convert(const std::string& from, const std::string& to, const double amount);
};

