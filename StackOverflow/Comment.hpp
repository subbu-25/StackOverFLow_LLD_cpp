
#ifndef COMMENT_HPP
#define COMMENT_HPP

#include <bits/stdc++.h>
using namespace std;

class Comment {
private:
    string comment_id;
    string user_id;
    string content;
public:
    Comment(string comment_id, string user_id, string content);
    string getCommentId() const;
    string getUserId() const;
    string getContent() const;
    void DisplayComment() const;
};

#endif 
