#include "CRestUsingCurl.h"
#include "CJsonCurrencyParser.h"
#include <iostream>

bool CRestUsingCurl::init()
{
    m_curl = curl_easy_init();
    std::string restRequestURL = m_server + m_latestCommand + "?access_key=" + m_accessKey;
    //restRequestURL = restRequestURL + "&base=" + m_fromCurrenyCode;
    restRequestURL = restRequestURL + "&format=1";
    if (m_curl)
    {
        curl_easy_setopt(m_curl,
            CURLOPT_URL,
            restRequestURL.c_str());

        curl_easy_setopt(m_curl,
            CURLOPT_WRITEFUNCTION,
            writeCallback);

        curl_easy_setopt(m_curl, 
            CURLOPT_WRITEDATA, 
            &m_readBuffer);

        return true;
    }
    return false;
}

std::string CRestUsingCurl::post()
{
    return std::string();
}

inline size_t CRestUsingCurl::writeCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    auto retVal = size * nmemb;
    if (!retVal)
        return 0;
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return static_cast<int>(size * nmemb);
}

CRestUsingCurl::CRestUsingCurl(const std::string& from, const std::string& to) :
    m_fromCurrenyCode(from),
    m_toCurrenyCode(to)
{
    if (init())
    {
        m_res = curl_easy_perform(m_curl);
        curl_easy_cleanup(m_curl);

        CJsonCurrencyParser jsonReader(m_fromCurrenyCode, m_readBuffer);
        m_conversionFactor = jsonReader.getCurrencyConversionFactor(m_toCurrenyCode);
    }
}

double CRestUsingCurl::getConversionFactor()
{
    return m_conversionFactor;
}
