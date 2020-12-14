#pragma once
#include "../../rest_curl/CCurlProxy.h"
#include "pch.h"

class MockCurlProxy :
	public CCurlProxy
{
public:
	static MockCurlProxy& instance()
	{
		static MockCurlProxy instance;
		return instance;
	}

	MOCK_METHOD(std::string, executeCurlRequest, (const std::string& from, const std::string& to), (override));
};
