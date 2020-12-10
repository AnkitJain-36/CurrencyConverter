#pragma once
#include <string>

class CCurrencyConverter
{
public:
	static double convert(const std::string& from, const std::string& to, const double amount);
};

