#ifndef FILE_APPENDER_HPP
#define FILE_APPENDER_HPP

#include <bits/stdc++.h>
using namespace std;
#include "LogAppender.hpp"

class FileAppender : public LogAppender {
    string   filename;
    ofstream file;
public:
    explicit FileAppender(const string& filename);
    ~FileAppender();
    void append(const LogMessage& lm) override;
};
#endif
