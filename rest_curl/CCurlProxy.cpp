#include "CCurlProxy.h"
#include "iostream"

/// <summary>
/// Get singleton instance
/// </summary>
/// <returns>Singleton instance</returns>
CCurlProxy& CCurlProxy::instance() {
    static CCurlProxy instance;
    return instance;
}

std::string CCurlProxy::executeCurlRequest(const std::string& from, const std::string& to)
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

        if (CURLE_OK != m_res)
        {
            std::cout << "Error in CURL call. Error Code:" << m_res << std::endl;
        }

        return readBuffer;
    }

    return "";
}

/// <summary>
/// Constrcutor
/// </summary>
CCurlProxy::CCurlProxy()
{
    //initialize curl
    m_res = CURLE_OK;
    m_curl = curl_easy_init();
}

/// <summary>
/// Destructor
/// </summary>
CCurlProxy::~CCurlProxy()
{
    // Cleanup curl after use
    curl_easy_cleanup(m_curl);
    m_curl = nullptr;
    curl_global_cleanup();
}

/// <summary>
/// Generates the REST command URL
/// </summary>
/// <param name="from">Base currency code</param>
/// <returns>Rest command URL</returns>
std::string CCurlProxy::generateRestRequestURL(const std::string& from)
{
    const std::string server{ "http://data.fixer.io/api/" };
    const std::string latestCommand{ "latest" };   // convert command is not available
    const std::string accessKey{ "4bd80c62e4c223602f9038e5512e182d" };

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
inline size_t CCurlProxy::writeCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    auto retVal = size * nmemb;
    if (!retVal)
        return 0;
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return static_cast<int>(size * nmemb);
}
