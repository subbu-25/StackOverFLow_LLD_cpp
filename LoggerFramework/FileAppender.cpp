#include "FileAppender.hpp"

FileAppender::FileAppender(const string& fname) : filename(fname) {
    file.open(filename, ios::app);          // create or append
}
FileAppender::~FileAppender() {
    if (file.is_open()) file.close();
}
void FileAppender::append(const LogMessage& lm) {
    if (file.is_open()) file << lm.getFormattedMessage() << endl;
}
