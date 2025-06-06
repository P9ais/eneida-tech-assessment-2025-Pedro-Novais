#include <map>
#include <iostream>
#include <string>

class MessageReceiver {
public:
    void receive(int id, const std::string& text) {
        messages[id] = text;
        processMessages();
    }

private:
    std::map<int, std::string> messages;
    int lastProcessedId = 0;

    void processMessages() {
        while (messages.size() >= 5) {
            int firstId = lastProcessedId + 1;
            int lastId = firstId + 4;

            for (firstId; firstId <= lastId; ++firstId) { //Used firstId in the if, but could've used an "int i = 0" instead, because the verified IDs won't be always the first Id
                if (messages.find(firstId) != messages.end()) { //Check if we can find the message with Id "firstId"
                    std::cout << "Message ID " << firstId << ": " << messages[firstId] << std::endl;
                    messages.erase(firstId);
                } else {
                    std::cout << "[faulty message for ID " << firstId << "]" << std::endl;
                }
            }

            lastProcessedId = lastId;
        }
    }
};