#define _CRT_SECURE_NO_WARNINGS  // Disable Visual Studio security warnings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "node.h"

// Initialize an empty queue
void initializeQueue(Queue* q) {
    q->head = NULL;
    q->tail = NULL;
}

// Return 1 if queue is empty, 0 otherwise
int isQueueEmpty(Queue* q) {
    return q->head == NULL;
}

// Add a user to the rear of the queue
void enqueue(Queue* q, User user) {
    // Allocate memory for the new node
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        fprintf(stderr, "Error: Memory allocation failed in enqueue\n");
        exit(EXIT_FAILURE);
    }
    
    newNode->data = user;
    newNode->next = NULL;

    if (isQueueEmpty(q)) {
        // First node: both head and tail point to it
        q->head = newNode;
        q->tail = newNode;
    }
    else {
        // Attach to rear and update tail
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

// Remove and return the user at the front of the queue
User dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        fprintf(stderr, "Error: Cannot dequeue from an empty queue\n");
        exit(EXIT_FAILURE);
    }
    
    QueueNode* temp = q->head;
    User       dequeuedUser = temp->data;

    // Move head forward
    q->head = q->head->next;

    // If queue is now empty, reset tail as well
    if (q->head == NULL) {
        q->tail = NULL;
    }

    free(temp); // Release the old front node
    return dequeuedUser;
}

// Randomly generate and enqueue 'count' users
// Returns 0 on success, non-zero on failure
int addRandomUsers(Queue* q, int count) {
    if (q == NULL || count <= 0) return 1; // Invalid input

    const char charset[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    size_t charsetSize = strlen(charset);

    for (int i = 0; i < count; i++) {
        User newUser;

        // Generate random 10-character username
        for (int j = 0; j < 10; j++) {
            newUser.username[j] = charset[rand() % (int)charsetSize];
        }
        newUser.username[10] = '\0';

        // Random level between 1 and 60
        newUser.level = (rand() % 60) + 1;

        // Random faction: 0=RED, 1=BLUE, 2=GREEN
        newUser.faction = (Faction)(rand() % 3);

        enqueue(q, newUser);
    }

    return 0; // Success
}
