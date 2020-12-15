// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CCurrencyConverter.h"
#include <algorithm>
#include "ErrorStrings.h"

/// <summary>
/// main function
/// </summary>
/// <returns>0 on successful execution</returns>
int main()
{
    const std::string euroCurrecyCode{ "EUR" };
    do {
        std::string fromCurrencyCode = euroCurrecyCode;
        std::string toCurrencyCode;
        double amount;

        // Get values
        std::cout << "Enter Values For Currency Conversion: \n";
        std::cout << "Amount:";
        std::cin >> amount;
        if (amount < 0)
        {
            std::cout << "Error: " << Error::NEGATIVE_AMOUNT << std::endl << std::endl;
            continue;
        }
        std::cout << "From:";
        //std::cin >> fromCurrencyCode;
        std::cout << euroCurrecyCode << std::endl;
        std::cout << "To:";
        std::cin >> toCurrencyCode;

        // Convert and Display Values
        std::string err{ "" };
        auto convertedValue = CCurrencyConverter::convert(fromCurrencyCode, toCurrencyCode, amount, err);
        if ("" == err)   // Case: No errors
        {
            std::cout << "Result:" << convertedValue << std::endl;
        }
        else 
        {
            std::cout << "Error:" << err << std::endl;
        }

        std::string cont;
        std::cout << "Countinue (y/n):";
        std::cin >> cont;
        std::transform(cont.begin(), cont.end(), cont.begin(), ::toupper);   // String to upper
        if ("Y" == cont)
        {
            std::cout << std::endl;
            continue;
        }
        break;
    } while (true);

    return 0;
}
