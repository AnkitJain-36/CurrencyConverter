#include "CConversionFactorFinder.h"
#include "CCurlProxy.h"

/// <summary>
/// Get conversion factor for converting a currency from a defined currency to another
/// </summary>
/// <param name="from">Base currency code</param>
/// <param name="to">Target currency code</param>
/// <returns>Conversion Factor</returns>
double CConversionFactorFinder::getConversionFactor(const std::string& from, const std::string& to)
{
    auto readBuffer = CCurlProxy::instance().executeCurlRequest(from, to);
    if (readBuffer.length() != 0)
    {
        // Parse resply
        m_jsonReader.setInput(readBuffer);
        // Get conversion factor
        return m_jsonReader.getCurrencyConversionFactor(to);
    }
    return -1;
}