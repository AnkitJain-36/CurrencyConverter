#include "CJsonParser.h"
#include "json/reader.h"
#include <iostream>

/// <summary>
/// Constructor (default)
/// </summary>
CJsonParser::CJsonParser()
{
    // do nothing
}

/// <summary>
/// Parameterized constructor with json string defined
/// </summary>
/// <param name="input">input string in Json format</param>
CJsonParser::CJsonParser(const std::string& input)
{
    setInput(input);
}

/// <summary>
/// Defines the input string
/// </summary>
/// <param name="input">input string in Json format</param>
void CJsonParser::setInput(const std::string& input)
{
    Json::CharReaderBuilder builder;
    std::string errs;
    const std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
    if (!reader->parse(input.c_str(), input.c_str() + input.length(), &m_root, &errs))
    {
        std::cout << "ERROR in parsing!" << std::endl << errs << std::endl;
        return;
    }
}

/// <summary>
/// Returns the input string in JSon format
/// </summary>
/// <returns>input string in JSon format</returns>
std::string CJsonParser::getValues()
{
    return m_root.toStyledString();
}
