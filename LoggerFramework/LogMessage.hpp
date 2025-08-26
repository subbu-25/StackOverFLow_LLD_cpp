#ifndef LOG_MESSAGE_HPP
#define LOG_MESSAGE_HPP

#include <bits/stdc++.h>
using namespace std;
#include "LogLevel.hpp"

class LogMessage {
    LogLevel level;
    string   message;
    string   timestamp;
    string   source;

public:
    LogMessage(LogLevel lvl, const string& msg, const string& src);

    LogLevel getLevel()     const { return level; }
    string   getMessage()   const { return message; }
    string   getTimestamp() const { return timestamp; }
    string   getSource()    const { return source; }
    string   getFormattedMessage() const;
};
#endif
