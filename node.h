
#ifndef NODE_H
#define NODE_H

// Enum for faction types  
typedef enum {
    RED,
    BLUE,
    GREEN
} Faction;

// User structure for game players
typedef struct {
    char    username[11]; // 10 characters + null terminator
    int     level;        // Level 1-60
    Faction faction;      // RED, BLUE, or GREEN
} User;

// A single node in the queue
typedef struct QueueNode {
    User              data; // User data stored in this node
    struct QueueNode* next; // Pointer to the next queue node
} QueueNode;

// Queue with head (front) and tail (rear) pointers
typedef struct {
    QueueNode* head; // Front of the queue (dequeue here)
    QueueNode* tail; // Rear of the queue  (enqueue here)
} Queue;

// Function declarations for queue operations
void initializeQueue(Queue* q);           // Initialize a blank queue
int  isQueueEmpty(Queue* q);              // Check if queue is empty
void enqueue(Queue* q, User user);        // Enqueue a node
User dequeue(Queue* q);                   // Dequeue a node
int  addRandomUsers(Queue* q, int count); // Add random users to queue

#endif
