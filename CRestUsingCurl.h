// Uses curl library for running REST

#include <string>
#include "curl/curl.h"

#pragma once
class CRestUsingCurl
{
    std::string m_fromCurrenyCode;
    std::string m_toCurrenyCode;

    CURL* m_curl = nullptr;
    CURLcode m_res;
    std::string m_readBuffer;

    double m_conversionFactor = 0;

    bool init();
    std::string post();
    static size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp);
public:
    CRestUsingCurl(const std::string& from, const std::string& to);
    double getConversionFactor();
};

