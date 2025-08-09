#ifndef POSTS_HPP
#define POSTS_HPP
#include "Comment.hpp"

#include<bits/stdc++.h>
using namespace std;


enum class PostType{
    QUESTION,ANSWER
};


class Post{
    private:
        string post_id;
        string user_id;
        string content;
        vector<Comment*>comments;
        vector<string>tags;
        vector<string> votes;
        PostType type;
        int score;
        bool accepted;
    public:
        Post(string postId, string userId, string content,
         const vector<string>& tags, PostType type);
        ~Post();



         string getPostId() const;
        string getUserId() const;
        string getContent() const;
        const vector<string>& getTags() const;
        const vector<Comment*>& getComments() const;
        int getScore() const;
        bool isAccepted() const;
        PostType getType() const;
        void addComment(Comment* comment);
        bool addVote(string user);
        bool removeVote(string user);
        void setAccepted(bool status);
        void displayInfo() const;
};


#endif