#include "posts.hpp"


Post::Post(string postId, string userId, string content,
           const vector<string>& tags, PostType type)
    : post_id(postId), user_id(userId), content(content), tags(tags),
      score(0), accepted(false), type(type) {
   
}
Post::~Post() {
    for (auto comment : comments) {
        delete comment;
    }
}
string Post::getPostId() const{
    return post_id;
}

string Post:: getUserId() const{
    return user_id;
}
string Post:: getContent() const{
    return content;
}
const vector<string>& Post::getTags() const {
     return tags;
     }
const vector<Comment*>& Post::getComments() const {
     return comments; 
    }
int Post:: getScore() const{
    return score;
}
bool Post:: isAccepted() const{
    return accepted;
}
PostType Post:: getType() const{
    return type;
}
void Post:: addComment(Comment* comment){
    comments.push_back(comment);
}
bool Post:: addVote(string user){
    if (find(votes.begin(), votes.end(), user) == votes.end()) {
        votes.push_back(user);
        score++;
        return true;
    }
    return false;
}
bool Post::removeVote(string user) {
    auto it = std::find(votes.begin(), votes.end(), user);
    if (it != votes.end()) {
        votes.erase(it);
        score--;
        return true;
    }
    return false;
}
void Post:: setAccepted(bool status){
    accepted=status;
}
void Post:: displayInfo() const{
    cout << "\nPost ID: " << post_id << endl;
    cout << "Type: " << (type == PostType::QUESTION ? "Question" : "Answer") << endl;
    cout << "Content: " << content << endl;
    cout << "Score: " << score << endl;
    cout << "Status: " << (accepted ? "Accepted" : "Not Accepted") << endl;
    
    if (!tags.empty()) {
        cout << "Tags: ";
        for (const auto& tag : tags) {
            cout << tag << " ";
        }
        cout << endl;
    }
    
    if (!comments.empty()) {
        cout << "Comments:" << endl;
        for (const auto& comment : comments) {
            comment->DisplayComment();
        }
    }
    
    
}