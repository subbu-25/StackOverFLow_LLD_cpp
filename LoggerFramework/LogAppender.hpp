#ifndef LOG_APPENDER_HPP
#define LOG_APPENDER_HPP

#include <bits/stdc++.h>
using namespace std;
#include "LogMessage.hpp"

class LogAppender {
public:
    virtual ~LogAppender()                    = default;
    virtual void append(const LogMessage& lm) = 0;
};
#endif
