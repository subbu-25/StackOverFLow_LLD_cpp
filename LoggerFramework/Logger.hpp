#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <bits/stdc++.h>
using namespace std;
#include "LogLevel.hpp"
#include "LogMessage.hpp"
#include "LogAppender.hpp"

class Logger {
    string               name;
    LogLevel             minLevel;
    vector<LogAppender*> appenders;           // raw pointers

    bool isLevelEnabled(LogLevel lvl) const { return lvl >= minLevel; }

public:
    explicit Logger(const string& name,
                    LogLevel minLevel = LogLevel::INFO);

    void addAppender(LogAppender* ap) { appenders.push_back(ap); }
    void setMinLevel(LogLevel lvl)    { minLevel = lvl; }

    void log  (LogLevel lvl, const string& msg);
    void trace(const string& msg) { log(LogLevel::TRACE, msg); }
    void debug(const string& msg) { log(LogLevel::DEBUG, msg); }
    void info (const string& msg) { log(LogLevel::INFO,  msg); }
    void warn (const string& msg) { log(LogLevel::WARN,  msg); }
    void error(const string& msg) { log(LogLevel::ERROR, msg); }
    void fatal(const string& msg) { log(LogLevel::FATAL, msg); }

    ~Logger();
};
#endif
