#ifndef USER_HPP
#define USER_HPP
#include<bits/stdc++.h>
using namespace std;
class User{
    private:
        string user_id;
        string username;
        string email;
        int reputation;
        vector<string>badges;
        bool active;
    public:
         User(string userId, string username, string email);
        string getUserId() const;
        string getUsername() const;
        string getEmail() const;
        int getReputation() const;
        const vector<string>& getBadges() const;
        bool isActive() const;
        void updateReputation(int points);
        void addBadge(string badge);
        void setActive(bool status);
        void displayInfo() const;



};
#endif