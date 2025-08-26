#include "LogMessage.hpp"

LogMessage::LogMessage(LogLevel lvl, const string& msg,
                       const string& src)
        : level(lvl), message(msg), source(src) {
    time_t now = time(nullptr);
    timestamp  = ctime(&now);
    timestamp.pop_back();                 // remove trailing '\n'
}

string LogMessage::getFormattedMessage() const {
    ostringstream oss;
    oss << "[" << timestamp << "] "
        << "[" << logLevelToString(level) << "] "
        << "[" << source << "] "
        << message;
    return oss.str();
}
