#include "CConversionFactorFinder.h"
#include "CCurlProxy.h"

/// <summary>
/// Constructor
/// </summary>
CConversionFactorFinder::CConversionFactorFinder()
{
    m_jsonReader = std::make_shared<CJsonCurrencyParser>();
    m_curlProxy = &CCurlProxy::instance();
}

/// <summary>
/// Get conversion factor for converting a currency from a defined currency to another
/// </summary>
/// <param name="from">Base currency code</param>
/// <param name="to">Target currency code</param>
/// <returns>Conversion Factor</returns>
double CConversionFactorFinder::getConversionFactor(const std::string& from, const std::string& to)
{
    auto readBuffer = m_curlProxy->executeCurlRequest(from, to);
    if (readBuffer.length() != 0)
    {
        // Parse resply
        m_jsonReader->setInput(readBuffer);
        // Get conversion factor
        return m_jsonReader->getCurrencyConversionFactor(to);
    }
    return -1;
}