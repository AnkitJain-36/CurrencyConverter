# CurrencyConverter
The project uses conversion factors obtained from https://fixer.io/ using REST for converting a defined amount from one currency to another.
Due to the limitation on the account (usage of a free fixer.io account), user may only set the base currency code to EUR.

Division using to and from currency conversion factors w.r.t EUR could have been used, but due to expected lack of precision, it was not done.

REST commands are implemented using cURL library.
Data is obtained in JSON format which is parsed using jsoncpp library. 

jsoncpp project link: https://github.com/open-source-parsers/jsoncpp

curl project link: https://github.com/curl/curl

Design
--------------

main.cpp contains the main function which obtains information from the user via command prompt and forwards the info to others classes for processing. The result is then displayed on comand prompt.

CCurrencyConverter acts as a utility file which allows for a static call to convert currency amount from one currency to another. It creates a CConversionFactorFinder class object for obtaining currency conversion factor.

CConversionFactorFinder is a class which uses the CCurlProxy for obtaining data from REST Server. The data is then parsed using CJsonCurrencyParser and the currency conversion factor is read and returned.

cURL requests are managed via CCurlProxy. The class allows for retrieving data from fixer.io using the base and target currency codes

JSON parsing is acomplished via CJsonCurrencyParser. The class inherits CJsonParser which defines how to parse a string (in JSON format) to a JSON::Value. CJsonCurrencyParser adds the functionality to return currency conversion factor after reading the same from the parsed JSON::Value object..

Directions to run the code
-------------------------
To run the code simply build the CurrencyConverter project as an executable (set by defualt).

To run the code's google test cases, 
1. Set the CurrencyConverter project as a static library. This can be achieved in Visual Studio in "Project Properties" by going to the "General" tab and setting the Configuration Type to "Static Library (.lib)". 
2. Clean the solution
3. Build the GTest Project
