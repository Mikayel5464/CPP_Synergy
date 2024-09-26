#ifndef __Conversation_H__
#define __Conversation_H__

#include <iostream>
#include <string>
#include <vector>
#include "user.h"
#include "message.h"

class User;
class Message;

class Conversation {
    public:
        Conversation() = default;
        Conversation(const Conversation&) = delete;
        Conversation(Conversation&&) = delete;
        Conversation& operator=(const User&) = delete;
        Conversation& operator=(User&&) = delete;
        void addMessage(Message* message);
        void addUser(User* user);
        std::vector<User*> getParticipants() const;
        std::vector<Message*> getMessages() const;
        ~Conversation();
    private:
        std::vector<User*> participants;
        std::vector<Message*> messageHistory;
};

#endif