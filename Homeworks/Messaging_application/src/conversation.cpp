#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "../headers/conversation.h"
#include "../headers/user.h"
#include "../headers/message.h"

void Conversation::addUser(User* user) {
    participants.push_back(user);
}

std::vector<User*> Conversation::getParticipants() const {
    return participants;
}

std::vector<Message*> Conversation::getMessages() const {
    return messageHistory;
}

void Conversation::addMessage(Message* message) {
    messageHistory.push_back(message);
}

Conversation::~Conversation() {
    for (int i = 0; i < messageHistory.size(); ++i) {
        delete messageHistory[i];
    }
}