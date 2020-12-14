#include "pch.h"
#include "memory"
#include "../../CConversionFactorFinder.h"
#include "MockJsonCurrencyParser.h"
#include "MockCurlProxy.h"

using ::testing::_;
using ::testing::Test;

class RestUsingCurlTest : public testing::Test
{
public:
	// Per-test-suite set-up.
	// Called before the first test in this test suite.
	// Can be omitted if not needed.
	static void SetUpTestSuite() 
	{
		
	}

	// Per-test-suite tear-down.
	// Called after the last test in this test suite.
	// Can be omitted if not needed.
	static void TearDownTestSuite() 
	{
		
	}

	// You can define per-test set-up logic as usual.
	virtual void SetUp() 
	{ 
		m_jsonCurrencyParser = std::make_shared<MockJsonCurrencyParser>();
		m_curlProxy = &MockCurlProxy::instance();
	}

	// You can define per-test tear-down logic as usual.
	virtual void TearDown() 
	{ 
		m_curlProxy = nullptr;
	}

protected:
	std::shared_ptr<MockJsonCurrencyParser> m_jsonCurrencyParser;
	MockCurlProxy* m_curlProxy = nullptr;
};

TEST_F(RestUsingCurlTest, getConversionFactorTest)
{
	// Mock curl proxy
	CConversionFactorFinder::instance().m_curlProxy = m_curlProxy;
	ON_CALL(*m_curlProxy, executeCurlRequest).WillByDefault([](const std::string& from, const std::string& to) {
		return std::string("{\
			\"success\":true,\
			\"timestamp\" : 1607599745,\
			\"base\" : \"EUR\",\
			\"date\" : \"2020-12-10\",\
			\"rates\" : {\
			\"USD\":1.209183\
			}\
			}");
		});
	EXPECT_CALL(*m_curlProxy, executeCurlRequest(_, _)).Times(1);

	// Execute getConversionFactor(_, _) function
	auto conversionFactor = CConversionFactorFinder::instance().getConversionFactor("EUR", "USD");
	EXPECT_EQ(conversionFactor, 1.209183);
}

TEST_F(RestUsingCurlTest, incorrectValueReceivedTest)
{
	// To prevent actual curl request, mock curl proxy
	ON_CALL(*m_curlProxy, executeCurlRequest).WillByDefault([](const std::string& from, const std::string& to) {
		return std::string("{\
			\"success\":true,\
			\"timestamp\" : 1607599745,\
			\"base\" : \"EUR\",\
			\"date\" : \"2020-12-10\",\
			\"rates\" : {\
			\"USD\": JJJ1.209183\
			}\
			}");
		});
	EXPECT_CALL(*m_curlProxy, executeCurlRequest(_, _)).Times(1);

	// Execute getConversionFactor(_, _) function
	auto conversionFactor = CConversionFactorFinder::instance().getConversionFactor("EUR", "USD");
	EXPECT_EQ(conversionFactor, 0.0);
}

TEST_F(RestUsingCurlTest, getConversionFactorTestEmptyStringTest)
{
	// Mock curl proxy
	CConversionFactorFinder::instance().m_curlProxy = m_curlProxy;
	ON_CALL(*m_curlProxy, executeCurlRequest).WillByDefault([](const std::string& from, const std::string& to) {
		return std::string("");
		});
	EXPECT_CALL(*m_curlProxy, executeCurlRequest(_, _)).Times(1);

	// Execute getConversionFactor(_, _) function
	auto conversionFactor = CConversionFactorFinder::instance().getConversionFactor("EUR", "USD");
	EXPECT_EQ(conversionFactor, -1);
}

TEST_F(RestUsingCurlTest, getCurrencyConversionFactorTest)
{
	// To prevent actual curl request, mock curl proxy
	ON_CALL(*m_curlProxy, executeCurlRequest).WillByDefault([](const std::string& from, const std::string& to) {
		return std::string("{\
			\"success\":true,\
			\"timestamp\" : 1607599745,\
			\"base\" : \"EUR\",\
			\"date\" : \"2020-12-10\",\
			\"rates\" : {\
			\"USD\":1.209183\
			}\
			}");
		});
	EXPECT_CALL(*m_curlProxy, executeCurlRequest(_, _)).Times(1);

	// Mock Json Reader
	CConversionFactorFinder::instance().m_jsonReader = m_jsonCurrencyParser;
	ON_CALL(*m_jsonCurrencyParser, getCurrencyConversionFactor).WillByDefault([](const std::string& currencyCode) {
			return 1.209183;
		});
	EXPECT_CALL(*m_jsonCurrencyParser, getCurrencyConversionFactor(_)).Times(1);

	// Execute getConversionFactor(_, _) function
	auto conversionFactor = CConversionFactorFinder::instance().getConversionFactor("EUR", "USD");
	EXPECT_EQ(conversionFactor, 1.209183);
}