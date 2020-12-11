#include <string>
#include "curl/curl.h"
#include "CJsonCurrencyParser.h"
#include "memory"

#pragma once
/// <summary>
/// Uses cURL for running REST commands
/// </summary>
class CRestUsingCurl
{
public:
    /// <summary>
    /// Get singleton instance
    /// </summary>
    /// <returns>Singleton instance</returns>
    static CRestUsingCurl& instance();

    /// <summary>
    /// Virtual destructor
    /// </summary>
    virtual ~CRestUsingCurl() {}

    /// <summary>
    /// Get conversion factor for converting a currency from a defined currency to another
    /// </summary>
    /// <param name="from">Base currency code</param>
    /// <param name="to">Target currency code</param>
    /// <returns>Conversion Factor</returns>
    double getConversionFactor(const std::string& from, const std::string& to);

private:
    /// <summary>
    /// Constructor
    /// </summary>
    CRestUsingCurl();

    // Delete copy constructor and disable copy using '=' operator
    CRestUsingCurl(const CRestUsingCurl&) = delete;
    CRestUsingCurl& operator=(const CRestUsingCurl&) = delete;

    /// <summary>
    /// curl object
    /// </summary>
    CURL* m_curl;
    /// <summary>
    /// cURL code obtained on executing command
    /// </summary>
    CURLcode m_res;
    /// <summary>
    /// Unnique pointer to json parser
    /// </summary>
    std::unique_ptr<CJsonCurrencyParser> m_jsonReader;

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

