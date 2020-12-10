#include "CJsonParser.h"
#include "json/reader.h"
#include <iostream>

CJsonParser::CJsonParser()
{
    // do nothing
}

CJsonParser::CJsonParser(const std::string& input)
{
    setInput(input);
}

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

std::string CJsonParser::getValues()
{
    return m_root.toStyledString();
}
