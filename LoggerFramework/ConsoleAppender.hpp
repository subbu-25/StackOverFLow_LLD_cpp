#ifndef CONSOLE_APPENDER_HPP
#define CONSOLE_APPENDER_HPP

#include <bits/stdc++.h>
using namespace std;
#include "LogAppender.hpp"

class ConsoleAppender : public LogAppender {
public:
    void append(const LogMessage& lm) override;
};
#endif
