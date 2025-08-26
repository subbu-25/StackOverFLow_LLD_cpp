#include "Logger.hpp"

Logger::Logger(const string& n, LogLevel lvl)
        : name(n), minLevel(lvl) {}

Logger::~Logger() {
    for (auto* p : appenders) delete p;
}

void Logger::log(LogLevel lvl, const string& msg) {
    if (!isLevelEnabled(lvl)) return;
    LogMessage lm(lvl, msg, name);
    for (auto* ap : appenders) ap->append(lm);
}
