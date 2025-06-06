#include "a3.hpp"

int main() {
    MessageReceiver receiver;
    receiver.receive(1, "Hello");
    receiver.receive(2, "World");
    receiver.receive(4, "Missing ID 3");
    receiver.receive(5, "Another");
    receiver.receive(6, "End of batch");

    return 0;
}
