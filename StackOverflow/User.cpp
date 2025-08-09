#include"User.hpp"
User::User(string userId, string username, string email)
    : user_id(userId), username(username), email(email), reputation(1), active(true) {}

        string User:: getUserId() const{
            return user_id;
        }
        string User:: getUsername() const{
            return username;
        }
        string User:: getEmail() const{
            return email;
        }
        int User::getReputation() const{
            return reputation;
        }
        const vector<string>&User:: getBadges() const{
            return badges;
        }
        bool User:: isActive() const{
            return active;
        }
        void User:: updateReputation(int points){
            reputation+=points;
        }
        void User:: addBadge(string badge){
            badges.push_back(badge);

        }
        void User:: setActive(bool status){
            active=status;
        }
        void User:: displayInfo() const{
            cout << "User: " << username << " (ID: " << user_id << ")" << endl;
            cout << "Email: " << email << endl;
            cout << "Reputation: " << reputation << endl;
            cout << "Status: " << (active ? "Active" : "Inactive") << endl;
    
            if (!badges.empty()) {
                cout << "Badges:" << endl;
                for (const auto& badge : badges) {
                    cout << "- " << badge << endl;
                }
            }
        }