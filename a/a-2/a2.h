#include <stdio.h>
#include <stdbool.h>
#include <string.h> // For memset

#define BUFFER_SIZE 128

// Define the circular buffer structure
typedef struct {
    unsigned char buffer[BUFFER_SIZE];
    volatile unsigned int head; // Where to write the next byte
    volatile unsigned int tail; // Where to read the next byte
    volatile unsigned int position; // Number of bytes currently in the buffer
} RingBuffer;

// Initialize the circular buffer
void init(RingBuffer *rb) {
    rb->head = 0;
    rb->tail = 0;
    rb->position = 0;
}