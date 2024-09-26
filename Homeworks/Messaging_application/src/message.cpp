#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "../headers/message.h"
#include "../headers/user.h"
#include "../headers/conversation.h"

Message::Message(User* user, Conversation* conv)
    : sender{user},
    conversation{conv},
    timestamp{std::chrono::system_clock::now()}
    {}

User* Message::getSender() const {
    return sender;
}

TextMessage::TextMessage(User* user, Conversation* conv, const std::string& textContent)
    : Message(user, conv),
    content{textContent}
    {}

void TextMessage::displayContent() const {
    std::cout << sender->getName() << " Text: " << content << std::endl;
}

std::string TextMessage::getMessageType() const {
    return "Text";
}

MultimediaMessage::MultimediaMessage(User* user, Conversation* conv, const std::string& path)
    : Message(user, conv),
    filePath{path},
    mediaType{"Multimedia"}
    {}

void MultimediaMessage::displayContent() const {
    std::cout << sender->getName() << " Multimedia - " << mediaType << " " << filePath << std::endl;
}

std::string MultimediaMessage::getMessageType() const {
    return mediaType;
}