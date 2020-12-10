// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CCurrencyConverter.h"

int main()
{
    do {
        std::string fromCurrencyCode;
        std::string toCurrencyCode;
        double amount;

        // Get values
        std::cout << "Enter Values For Currency Conversion: \n";
        std::cout << "From:";
        std::cin >> fromCurrencyCode;
        std::cout << "To:";
        std::cin >> toCurrencyCode;
        std::cout << "Amount:";
        std::cin >> amount;

        // Convert and Display Values
        std::cout << "Result:" << CCurrencyConverter::convert(fromCurrencyCode, toCurrencyCode, amount) << std::endl;
    } while (true);

    return 0;
}
