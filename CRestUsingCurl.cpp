#include "CRestUsingCurl.h"

/// <summary>
/// Get singleton instance
/// </summary>
/// <returns>Singleton instance</returns>
CRestUsingCurl& CRestUsingCurl::instance() {
    static CRestUsingCurl instance;
    return instance;
}

/// <summary>
/// Virtual destructor
/// </summary>

inline CRestUsingCurl::~CRestUsingCurl()
{
    // Cleanup curl after use
    curl_easy_cleanup(m_curl);
}

/// <summary>
/// Constructor
/// </summary>
CRestUsingCurl::CRestUsingCurl()
{
    m_jsonReader = std::make_unique<CJsonCurrencyParser>();
    //initialize curl
    m_curl = curl_easy_init();
}

/// <summary>
/// Get conversion factor for converting a currency from a defined currency to another
/// </summary>
/// <param name="from">Base currency code</param>
/// <param name="to">Target currency code</param>
/// <returns>Conversion Factor</returns>
double CRestUsingCurl::getConversionFactor(const std::string& from, const std::string& to)
{


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

        // Parse resply
        m_jsonReader->setInput(readBuffer);
        // Get conversion factor
        return m_jsonReader->getCurrencyConversionFactor(to);
    }

    return -1;
}

/// <summary>
/// Generates the REST command URL
/// </summary>
/// <param name="from">Base currency code</param>
/// <returns>Rest command URL</returns>
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

/// <summary>
/// WriteCallback function for cURL CURLOPT_WRITEFUNCTION
/// </summary>
/// <param name="contents">Data received</param>
/// <param name="size">Size of each memeber</param>
/// <param name="nmemb">Number of members</param>
/// <param name="userp">User reply</param>
/// <returns>Size of reply</returns>
inline size_t CRestUsingCurl::writeCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    auto retVal = size * nmemb;
    if (!retVal)
        return 0;
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return static_cast<int>(size * nmemb);
}
