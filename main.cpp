// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CCurrencyConverter.h"

/// <summary>
/// main function
/// </summary>
/// <returns>0 on successful execution</returns>
int main()
{
    const std::string euroCurrecyCode = "EUR";
    do {
        std::string fromCurrencyCode = euroCurrecyCode;
        std::string toCurrencyCode;
        double amount;

        // Get values
        std::cout << "Enter Values For Currency Conversion: \n";
        std::cout << "Amount:";
        std::cin >> amount;
        std::cout << "From:";
        //std::cin >> fromCurrencyCode;
        std::cout << "EUR" << std::endl;
        std::cout << "To:";
        std::cin >> toCurrencyCode;

        // Convert and Display Values
        auto convertedValue = CCurrencyConverter::convert(fromCurrencyCode, toCurrencyCode, amount);
        if (convertedValue == 0.0)
        {
            std::cout << "Error: Country Code not found." << std::endl;
        }
        else
        {
            std::cout << "Result:" << convertedValue << std::endl;
        }

        std::string cont;
        std::cout << "Countinue (y/n):";
        std::cin >> cont;
        if (cont != "y")
            break;

        std::cout << std::endl;
    } while (true);

    return 0;
}
