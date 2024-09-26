#ifndef __Message_H__
#define __Message_H__

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "user.h"
#include "conversation.h"

class User;
class Conversation;

class Message {
    public:
        Message(User* user, Conversation* conv);
        Message(const Message&) = delete;
        Message(Message&&) = delete;
        Message& operator=(const Message&) = delete;
        Message& operator=(Message&&) = delete;
        virtual void displayContent() const = 0;
        virtual std::string getMessageType() const = 0;
        User* getSender() const;
        virtual ~Message() = default;
    protected:
        User* sender;
        Conversation* conversation;
        std::chrono::time_point<std::chrono::system_clock> timestamp;
};

class TextMessage : public Message {
    public:
        TextMessage(User* user, Conversation* conv, const std::string& textContent);
        void displayContent() const override;
        std::string getMessageType() const override;
        ~TextMessage() override = default;
    private:
        std::string content;
};

class MultimediaMessage : public Message {
    public:
        MultimediaMessage(User* user, Conversation* conv, const std::string& path);
        void displayContent() const override;
        std::string getMessageType() const override;
        ~MultimediaMessage() override = default;
    private:
        std::string filePath;
        std::string mediaType;
};

class MessagingManager {
    public:
        virtual void sendMessage(Message* message) = 0;
        virtual void receiveMessage(Message* message) = 0;
        virtual std::vector<Message*> viewConversationHistory(Conversation* conversation) const = 0;
        virtual ~MessagingManager() = default;
};

#endif