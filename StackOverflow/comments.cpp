// Comment.cpp
#include "Comment.hpp"

Comment::Comment(string comment_id, string user_id, string content)
    : comment_id(comment_id), user_id(user_id), content(content) {}

string Comment::getCommentId() const {
    return comment_id;
}

string Comment::getUserId() const {
    return user_id;
}

string Comment::getContent() const {
    return content;
}

void Comment::DisplayComment() const {
    cout << user_id << " has commented " << content << endl;
}
