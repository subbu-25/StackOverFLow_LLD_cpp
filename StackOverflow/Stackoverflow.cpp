#include "Stackoverflow.hpp"

Stackoverflow::Stackoverflow():usercount(1),postcount(1),commentsconut(1){}

Stackoverflow::~Stackoverflow() {
    for (auto user : users) delete user;
    for (auto post : posts) delete post;
}

User* Stackoverflow::registerUser(string name, string email){
    string user_id=generateUserid();
    User* user=new User(user_id,name,email);
    users.push_back(user);
    return user;

}
void Stackoverflow::removeUser(string user_id){
    for (auto it = users.begin(); it != users.end(); ++it) {
        if ((*it)->getUserId() == user_id) {
            delete *it;             
            users.erase(it);         
            break;                   
        }
    }
}
Post* Stackoverflow::addQuestion(string user_id,string content,string ,vector<string>tags){

    if(!findUser(user_id))return nullptr;
    
    string post_id = generatePostid();
    Post* question=new Post(post_id,user_id,content,tags,PostType::QUESTION);
    posts.push_back(question);
    return question;
}
Post* Stackoverflow:: addAnswer(string user_id,string question_id,string content){
    if(!findUser(user_id))return nullptr;
    string postId = generatePostid();
    Post* answer=new Post(postId, user_id, content, vector<string>(), PostType::ANSWER);
    posts.push_back(answer);
    return answer;
}
Comment* Stackoverflow::addComment( string userId,  string postId,
                                  string content) {
    if (!findUser(userId)) return nullptr;
    
    Post* post = findPost(postId);
    if (!post) return nullptr;
    
    string commentId = generateCommentid();
    Comment* comment = new Comment(commentId, userId, content);
    post->addComment(comment);
    return comment;
}
bool Stackoverflow::upVote(string user_id,string post_id){
    User* user=findUser(user_id);
    Post* post=findPost(post_id);
    if(!user || !post||post->getUserId()==user_id)return false;
    if(post->addVote(user_id)){
        updateUserReputation(post->getUserId(), 10);  
        return true;
    }
    return false;

}
bool Stackoverflow::downVote(string user_id,string post_id){
    Post* post = findPost(post_id);
    if (!post) return false;
    
    if (post->removeVote(user_id)) {
        updateUserReputation(post->getUserId(), -10);  // -10 for removed upvote
        return true;
    }
    return false;

}
 bool Stackoverflow::acceptAnswer(string user_id,string answer_id){
     Post* answer = findPost(answer_id);
    if (!answer || answer->getType() != PostType::ANSWER) return false;
    answer->setAccepted(true);
    updateUserReputation(answer->getUserId(), 15);  // +15 for accepted answer
    return true;
 }
 vector<Post*>Stackoverflow::searchQuestion(string tag){
     vector<Post*> results;
    for (const auto& post : posts) {
        if (post->getType() == PostType::QUESTION) {
            const auto& tags = post->getTags();
            if (find(tags.begin(), tags.end(), tag) != tags.end()) {
                results.push_back(post);
            }
        }
    }
    return results;
 }
 void Stackoverflow::displayUserProfile( string user_id)  {
    User* user = findUser(user_id);
    if (!user) return;
    
    user->displayInfo();
    
    cout << "\nPosts by " << user->getUsername() << ":" << endl;
    for (const auto& post : posts) {
        if (post->getUserId() == user_id) {
            post->displayInfo();
        }
    }
}


void Stackoverflow::displayQuestion( string question_id)  {
    Post* question = findPost(question_id);
    if (!question || question->getType() != PostType::QUESTION) return;
    
    question->displayInfo();
}


 User* Stackoverflow::findUser( string userId)  {
    for ( User* user : users) {
        if (user->getUserId() == userId) {
            return user;
        }
    }
    return nullptr;
}

Post* Stackoverflow::findPost( string postId)  {
    for (Post* post : posts) {
        if (post->getPostId() == postId) {
            return post;
        }
    }
    return nullptr;
}
void Stackoverflow::updateUserReputation( string userId, int points) {
    if (User* user = findUser(userId)) {
        user->updateReputation(points);
    }
}

string Stackoverflow::generateUserid() {
    return "U" + to_string(usercount++);
}

string Stackoverflow::generatePostid() {
    return "P" + to_string(postcount++);
}

string Stackoverflow::generateCommentid() {
    return "C" + to_string(commentsconut++);
} 

