// Uses curl library for running REST

#include <string>
#include "curl/curl.h"

#pragma once
class CRestUsingCurl
{
    const std::string m_server = "http://data.fixer.io/api/";
    const std::string m_latestCommand = "latest";
    const std::string m_accessKey = "4bd80c62e4c223602f9038e5512e182d";

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

