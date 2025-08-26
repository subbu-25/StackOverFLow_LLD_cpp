#include "ConsoleAppender.hpp"

void ConsoleAppender::append(const LogMessage& lm) {
    cout << lm.getFormattedMessage() << endl;
}
