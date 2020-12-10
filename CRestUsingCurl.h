// Uses curl library for running REST

#include <string>
#include "curl/curl.h"

#pragma once
class CRestUsingCurl
{
    std::string m_fromCurrenyCode;
    std::string m_toCurrenyCode;

    CURL* m_curl;
    CURLcode m_res;
    std::string m_readBuffer;

    bool init();
    std::string post();
    static size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp);
public:
    CRestUsingCurl(const std::string& from, const std::string& to);
};

