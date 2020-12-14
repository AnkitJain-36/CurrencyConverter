#pragma once

#include "curl/curl.h"
#include "string"
#include "memory"
class CCurlProxy
{
public:
    /// <summary>
    /// Get singleton instance
    /// </summary>
    /// <returns>Singleton instance</returns>
    static CCurlProxy& instance();

    /// <summary>
    /// Execute curl request
    /// </summary>
    /// <param name="from">Base currency code</param>
    /// <param name="to">Target currency code</param>
    /// <returns>Curl Request Reply</returns>
    virtual std::string executeCurlRequest(const std::string& from, const std::string& to);

protected:
    /// <summary>
    /// Constructor
    /// </summary>
    CCurlProxy();

    /// <summary>
    /// Destructor
    /// </summary>
    virtual ~CCurlProxy();

    /// <summary>
    /// curl object
    /// </summary>
    CURL* m_curl = nullptr;
    /// <summary>
    /// cURL code obtained on executing command
    /// </summary>
    CURLcode m_res;

    /// <summary>
    /// Generates the REST command URL
    /// </summary>
    /// <param name="from">Base currency code</param>
    /// <returns>Rest command URL</returns>
    std::string generateRestRequestURL(const std::string& from);

    /// <summary>
    /// WriteCallback function for cURL CURLOPT_WRITEFUNCTION
    /// </summary>
    /// <param name="contents">Data received</param>
    /// <param name="size">Size of each memeber</param>
    /// <param name="nmemb">Number of members</param>
    /// <param name="userp">User reply</param>
    /// <returns>Size of reply</returns>
    static size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp);
};

