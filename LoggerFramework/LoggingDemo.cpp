#include <bits/stdc++.h>
using namespace std;
#include "Logger.hpp"
#include "ConsoleAppender.hpp"
#include "FileAppender.hpp"

int main() {
    Logger log("MyApp");

    log.addAppender(new ConsoleAppender);
    log.addAppender(new FileAppender("app.log"));

    log.info ("Application started");
    log.warn ("Low disk space");
    log.error("Could not open config");
    log.fatal("Fatal error – exiting");

    log.setMinLevel(LogLevel::DEBUG);
    log.debug("Debugging enabled");

    return 0;
}
