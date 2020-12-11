#include "CRestUsingCurl.h"

CRestUsingCurl& CRestUsingCurl::instance() {
    static CRestUsingCurl instance;
    return instance;
}

CRestUsingCurl::CRestUsingCurl()
{
    m_jsonReader = std::make_unique<CJsonCurrencyParser>();
}

double CRestUsingCurl::getConversionFactor(const std::string& from, const std::string& to)
{
    //initialize
    m_curl = curl_easy_init();

    if (m_curl)
    {
        auto requestUrl = generateRestRequestURL(from);
        std::string readBuffer;

        // Set rest request URL
        curl_easy_setopt(m_curl,
            CURLOPT_URL,
            requestUrl.c_str());

        // Set writeback function callback
        curl_easy_setopt(m_curl,
            CURLOPT_WRITEFUNCTION,
            writeCallback);

        // Set writedata variable
        curl_easy_setopt(m_curl,
            CURLOPT_WRITEDATA,
            &readBuffer);

        // Peform cURL function
        m_res = curl_easy_perform(m_curl);

        // Cleanup after use
        curl_easy_cleanup(m_curl);

        // Parse resply
        m_jsonReader->setInput(readBuffer);
        // Get conversion factor
        return m_jsonReader->getCurrencyConversionFactor(to);
    }

    return -1;
}

std::string CRestUsingCurl::generateRestRequestURL(const std::string& from)
{
    const std::string server = "http://data.fixer.io/api/";
    const std::string latestCommand = "latest";   // convert command is not available
    const std::string accessKey = "4bd80c62e4c223602f9038e5512e182d";

    std::string restRequestURL = server + latestCommand + "?access_key=" + accessKey;
    //restRequestURL = restRequestURL + "&base=" + from;
    restRequestURL = restRequestURL + "&format=1";

    return restRequestURL;
}

inline size_t CRestUsingCurl::writeCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    auto retVal = size * nmemb;
    if (!retVal)
        return 0;
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return static_cast<int>(size * nmemb);
}
