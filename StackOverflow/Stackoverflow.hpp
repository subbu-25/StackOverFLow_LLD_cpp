#ifndef STACKOVERFLOW_HPP
#define  STACKOVERFLOW_HPP

#include "Comment.hpp"
#include "posts.hpp"
#include "User.hpp"
#include<bits/stdc++.h>
using namespace std;



class Stackoverflow{
    private:
        vector<User*>users;
        vector<Post*>posts;
        int usercount;
        int postcount;
        int commentsconut;
    public:
        Stackoverflow();
        ~Stackoverflow();
        User* registerUser(string name, string email);
        void removeUser(string user_id);


        Post* addQuestion(string user_id,string content,string ,vector<string>tags);
        Post* addAnswer(string user_id,string question_id,string content);
        Comment* addComment(string user_id,string content,string post_id);


        bool upVote(string user_id,string post_id);
        bool downVote(string user_id,string post_id);
        bool acceptAnswer(string user_id,string answer_id);


        vector<Post*>searchQuestion(string tag);
        void displayUserProfile(string user_id);
        void displayQuestion(string question_id );


        private:

        User* findUser(string user_id);
        Post* findPost(string post_id);
        void updateUserReputation(string userid,int points);
        string generateUserid();
        string generatePostid();
        string generateCommentid();



};


#endif 
