#include "pch.h"
#include "memory"
#include "../../CConversionFactorFinder.h"
#include "MockJsonCurrencyParser.h"
#include "MockCurlProxy.h"

class RestUsingCurlTest
{
public:
	RestUsingCurlTest()
	{
		m_jsonCurrencyParser = std::make_shared<MockJsonCurrencyParser>();
		m_curlProxy = &MockCurlProxy::instance();
	}

protected:
	std::shared_ptr<MockJsonCurrencyParser> m_jsonCurrencyParser;
	MockCurlProxy* m_curlProxy;
};

TEST_F(RestUsingCurlTest, iniTest)
{
	CConversionFactorFinder factorFinder;
	factorFinder.m_jsonReader = m_jsonCurrencyParser;
	factorFinder.m_curlProxy = m_curlProxy;
	EXPECT_CALL(*(m_jsonCurrencyParser.get()), getCurrencyConversionFactor("USD")).Times(1);
	EXPECT_CALL(*m_curlProxy, executeCurlRequest("EUR", "USD")).Times(1);

	factorFinder.getConversionFactor("EUR", "USD");
}