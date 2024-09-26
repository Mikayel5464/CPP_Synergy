#include <iostream>
#include "../headers/user.h"
#include "../headers/conversation.h"
#include "../headers/message.h"

int main() {
    User user1("Alice", "alice@example.com");
    User user2("Bob", "bob@example.com");

    user1.createConversation(user2);

    Conversation* conv = user1.getConversations()[0];

    TextMessage* msg1 = new TextMessage(&user1, conv, "Hello Bob. Send me a picture please.");
    MultimediaMessage* msg2 = new MultimediaMessage(&user2, conv, "/Desktop/images/photo.png");

    conv->addMessage(msg1);
    conv->addMessage(msg2);

    for (int i = 0; i < conv->getMessages().size(); ++i) {
        conv->getMessages()[i]->displayContent();
    }

    return 0;
}
