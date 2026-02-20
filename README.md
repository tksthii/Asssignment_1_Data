# Assignment 1: Queue Data Structure for Game Users

## Description
Implementation of a queue data structure using linked nodes to manage game users. Each user has a unique username, level (1-60), and faction (Red, Blue, or Green).

## Summary

### Code Explanation

This project implements a **queue (FIFO - First In First Out)** data structure from scratch using **linked nodes** to manage game users in a multiplayer game environment. The implementation demonstrates fundamental data structure concepts including:

**Core Components:**

1. **Data Structures (node.h):**
   - `Faction` enum: Represents three team types (RED, BLUE, GREEN)
   - `User` struct: Stores game player information (username, level, faction)
   - `QueueNode` struct: Linked list node containing User data and pointer to next node
   - `Queue` struct: Maintains head (front) and tail (rear) pointers for efficient operations

2. **Queue Operations (queue.c):**
   - **initializeQueue()**: Sets up empty queue with NULL head/tail pointers
   - **isQueueEmpty()**: Checks if queue has any elements
   - **enqueue()**: Adds new user to the rear of queue (O(1) time complexity)
   - **dequeue()**: Removes and returns user from front of queue (O(1) time complexity)
   - **addRandomUsers()**: Generates N random users with unique attributes

3. **Testing Program (main.c):**
   - Accepts user count via command line or interactive input
   - Initializes queue and populates with random users
   - Demonstrates FIFO behavior by dequeuing all users in order
   - Displays each user's complete information

### Functionality Demonstration

**Step 1: Queue Initialization**
```
Queue q;
initializeQueue(&q);
```
Creates empty queue with head = NULL, tail = NULL

**Step 2: Random User Generation**
```
addRandomUsers(&q, 5);
```
Generates 5 users with:
- Random usernames: e.g., "a3k5m9x2b7" (10 alphanumeric chars)
- Random levels: 1-60 (e.g., 42, 15, 58)
- Random factions: RED, BLUE, or GREEN

**Step 3: FIFO Dequeue Process**
```
while (!isQueueEmpty(&q)) {
    User u = dequeue(&q);
    // Display user info
}
```

**Example Execution Flow:**
```
Input: ./game_queue 3

Process:
1. Initialize empty queue: [empty]
2. Enqueue User #1 (Alice, L:25, RED): [User1]
3. Enqueue User #2 (Bob, L:40, BLUE): [User1 -> User2]
4. Enqueue User #3 (Charlie, L:10, GREEN): [User1 -> User2 -> User3]

Output (FIFO order):
User #1: Alice, L:25, RED     (first in, first out)
User #2: Bob, L:40, BLUE      
User #3: Charlie, L:10, GREEN (last in, last out)
```

**Key Features Demonstrated:**
- ✅ **FIFO Ordering**: Users are dequeued in exact enqueue order
- ✅ **Dynamic Memory**: Queue grows/shrinks with malloc/free
- ✅ **O(1) Operations**: Both enqueue and dequeue are constant time
- ✅ **Error Handling**: Validates input and checks memory allocation
- ✅ **Randomization**: Generates diverse user profiles for testing
- ✅ **Clean Separation**: Data structures, operations, and testing are well-organized

**Use Case Example:**
In a multiplayer game matchmaking system, this queue ensures:
- Players join lobby in arrival order (fairness)
- First player to queue gets matched first
- System handles dynamic player counts efficiently
- All player data (username, level, faction) is preserved

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
