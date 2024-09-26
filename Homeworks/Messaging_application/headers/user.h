#ifndef __User_H__
#define __User_H__

#include <iostream>
#include <string>
#include <vector>
#include "conversation.h"

class Conversation;
class Message;

class User {
    public:
        User(std::string userName, std::string userContact);
        User(const User&) = delete;
        User(User&&) = delete;
        User& operator=(const User& otherUser) = delete;
        User& operator=(User&&) = delete;
        std::string getName() const;
        void createConversation(User& user);
        void manageSettings();
        void addConversation(Conversation* conversation);
        std::vector<Conversation*> getConversations() const;
        ~User();
    private:
        std::string name;
        std::string contactInfo;
        std::vector<Conversation*> conversations;
};

#endif