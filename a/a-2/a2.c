#include "a2.h"

// Push a byte into the buffer
bool push(RingBuffer *rb, unsigned char data) {
    if (rb->position == BUFFER_SIZE) {
        // Buffer is full
        return false;
    }

    rb->buffer[rb->head] = data;
    rb->head = (rb->head + 1) % BUFFER_SIZE; // Establishing the ring 1%128=1 ... 128%128=0
    rb->position++;
    return true;
}

// Function to pop a byte from the buffer
bool pop(RingBuffer *rb, unsigned char *data) {
    if (rb->position == 0) {
        // Buffer is empty
        return false;
    }

    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % BUFFER_SIZE; // Wrap around if necessary
    rb->position--;
    return true;
}

// Function to check if the buffer is empty
bool is_empty(const RingBuffer *rb) {
    return rb->position == 0; //Returns False if not empty and True if empty
}

// Function to check if the buffer is full
bool is_full(const RingBuffer *rb) {
    return rb->position == BUFFER_SIZE; //Returns False if not full and True if full
}

// --- Example Usage ---
// int main() {
//     RingBuffer myBuffer;
//     init(&myBuffer);

//     printf("Is buffer empty? %s\n", is_empty(&myBuffer) ? "Yes" : "No");
//     printf("Is buffer full? %s\n", is_full(&myBuffer) ? "Yes" : "No");

//     // Push some data
//     for (int i = 0; i < 50; ++i) {
//         if (push(&myBuffer, (unsigned char)('A' + (i % 26)))) {
//             printf("Pushed: %c\n", (unsigned char)('A' + (i % 26)));
//         } else {
//             printf("Failed to push. Buffer full.\n");
//             break;
//         }
//     }

//     printf("Is buffer empty? %s\n", is_empty(&myBuffer) ? "Yes" : "No");
//     printf("Is buffer full? %s\n", is_full(&myBuffer) ? "Yes" : "No");

//     // Pop some data
//     unsigned char received_data;
//     printf("\nPopping data:\n");
//     for (int i = 0; i < 30; ++i) {
//         if (pop(&myBuffer, &received_data)) {
//             printf("Popped: %c\n", received_data);
//         } else {
//             printf("Failed to pop. Buffer empty.\n");
//             break;
//         }
//     }

//     printf("Is buffer empty? %s\n", is_empty(&myBuffer) ? "Yes" : "No");
//     printf("Is buffer full? %s\n", is_full(&myBuffer) ? "Yes" : "No");

//     // Try to fill the buffer completely
//     printf("\nAttempting to fill the buffer completely...\n");
//     while (push(&myBuffer, 'X')) {
//         // Keep pushing 'X' until full
//     }
//     printf("Is buffer full now? %s\n", is_full(&myBuffer) ? "Yes" : "No");

//     // Try to push one more
//     if (!push(&myBuffer, 'Y')) {
//         printf("Cannot push 'Y', buffer is full as expected.\n");
//     }

//     // Pop all remaining data
//     printf("\nPopping all remaining data:\n");
//     while (pop(&myBuffer, &received_data)) {
//         printf("Popped: %c\n", received_data);
//     }
//     printf("Is buffer empty now? %s\n", is_empty(&myBuffer) ? "Yes" : "No");

//     return 0;
// }