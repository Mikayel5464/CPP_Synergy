#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "../headers/user.h"
#include "../headers/conversation.h"

User::User(std::string userName, std::string userContact)
    : name{userName},
    contactInfo{userContact}
    {}

std::string User::getName() const {
    return name;
}

void User::manageSettings() {
    std::cout << "Managing settings for " << name << std::endl;
}

std::vector<Conversation*> User::getConversations() const {
    return conversations;
}

void User::addConversation(Conversation* conversation) {
    conversations.push_back(conversation);
}

void User::createConversation(User& otherUser) {
    Conversation* newConversation = new Conversation();
    
    newConversation->addUser(this);
    newConversation->addUser(&otherUser);

    this->addConversation(newConversation);
    otherUser.addConversation(newConversation);

    std::cout << "Conversation created between " << this->name << " and " << otherUser.getName() << std::endl;
}

User::~User() {
    for (int i = 1; i <= conversations.size(); ++i) {
        delete conversations[i];
    }
}
