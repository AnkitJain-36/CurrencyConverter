#include "curl/curl.h"
#include <string>

#pragma once
class CRestUsingCurl
{
    bool init();
    std::string post();

public:
    CRestUsingCurl();
};

