# Assignment 1: Queue Data Structure for Game Users

## Description
Implementation of a queue data structure using linked nodes to manage game users. Each user has a unique username, level (1-60), and faction (Red, Blue, or Green).

## Files
- **node.h** - Header file containing all struct definitions and function declarations
- **queue.c** - Implementation of queue operations (initialize, enqueue, dequeue, isEmpty)
- **main.c** - Testing program demonstrating queue functionality

## Features
- **Queue Operations:**
  - Initialize empty queue
  - Check if queue is empty
  - Enqueue (add to rear)
  - Dequeue (remove from front)
  - FIFO (First In First Out) behavior

- **Random User Generation:**
  - 10-character alphanumeric usernames
  - Random levels between 1-60
  - Random faction selection (Red/Blue/Green)

- **Error Handling:**
  - Input validation
  - Memory allocation checks
  - Command line argument support

## Requirements
- C compiler (gcc or Visual Studio)
- Standard C libraries

## Compilation

### macOS/Linux:
```bash
gcc main.c queue.c -o game_queue
./game_queue 10
```

### Windows (Visual Studio):
1. Open `Asssignment_1_Data.sln`
2. Build Solution (Ctrl+Shift+B)
3. Run (F5)

## Usage

### With command line argument:
```bash
./game_queue 5
```

### Interactive mode:
```bash
./game_queue
Enter the number of users to add to the queue: 5
```

## Output Example
```
Queue initialized successfully.

Adding 5 random users to the queue...
Successfully added 5 users to the queue.

=== Dequeuing all users ===
-----------------------------------------------------------
User #1:
  Username: a3k5m9x2b7
  Level:    42
  Faction:  Blue
-----------------------------------------------------------
User #2:
  Username: z8p1n4q6y0
  Level:    15
  Faction:  Red
-----------------------------------------------------------
...

All users have been dequeued. Queue is now empty.
```

## Data Structures

### User
```c
typedef struct {
    char    username[11];  // 10 chars + null terminator
    int     level;         // 1-60
    Faction faction;       // RED, BLUE, or GREEN
} User;
```

### Queue
```c
typedef struct {
    QueueNode* head;  // Front of queue
    QueueNode* tail;  // Rear of queue
} Queue;
```

## Author
Student Implementation

## Date
February 2026
