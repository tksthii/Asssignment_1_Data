# Assignment 1: Queue Data Structure for Game Users

## Description
Implementation of a queue (FIFO) data structure using linked nodes to manage game users.

## Code Summary

This project implements a **queue data structure** from scratch using linked nodes. The queue follows FIFO (First In First Out) principle - the first user added is the first one removed.

**How It Works:**
1. **Initialization**: Empty queue with `head = NULL` and `tail = NULL`
2. **Enqueue**: New users are added to the rear (tail) of the queue in O(1) time
3. **Dequeue**: Users are removed from the front (head) of the queue in O(1) time
4. **Memory Management**: Each node is dynamically allocated with `malloc()` and freed with `free()` to prevent memory leaks

**Functionality Demonstration:**
```
Input: ./game_queue 3

Process:
1. Initialize empty queue
2. Generate 3 random users:
   - User1: username="a3k5m9x2b7", level=42, faction=BLUE
   - User2: username="z8p1n4q6y0", level=15, faction=RED  
   - User3: username="m7w2q5t8n1", level=58, faction=GREEN

3. Enqueue in order: [User1] → [User1, User2] → [User1, User2, User3]

4. Dequeue in FIFO order:
   First out: User1 (a3k5m9x2b7, L:42, BLUE)
   Second out: User2 (z8p1n4q6y0, L:15, RED)
   Last out: User3 (m7w2q5t8n1, L:58, GREEN)
```

**Key Implementation Details:**
- `QueueNode` contains `User data` (embedded by value) and `next` pointer
- Both `enqueue()` and `dequeue()` operate in constant time O(1)
- Safety checks prevent crashes (empty queue check, malloc validation)
- Random user generation creates 10-char alphanumeric usernames, levels 1-60, and random factions

## Requirements
1. **Data Structures:**
   - `User` struct: username (10 chars), level (1-60), faction (RED/BLUE/GREEN)
   - `QueueNode` struct: contains `User data` and `next` pointer
   - `Queue` struct: head and tail pointers

2. **Queue Operations:**
   - `initializeQueue()` - Initialize empty queue
   - `isQueueEmpty()` - Check if queue is empty
   - `enqueue()` - Add user to rear (O(1))
   - `dequeue()` - Remove user from front (O(1))
   - `addRandomUsers()` - Generate N random users

3. **Program Features:**
   - Accept user count via command line or input
   - Generate random usernames (10 alphanumeric chars)
   - Display all users in FIFO order
   - Proper error handling and memory management

## Files
- **node.h** - Struct definitions and function declarations
- **queue.c** - Queue operations implementation
- **main.c** - Testing program

## Compilation & Usage

**macOS/Linux:**
```bash
gcc main.c queue.c -o game_queue
./game_queue 10
```

**Windows (Visual Studio):**
Open `Asssignment_1_Data.sln` and build

## Author
Ngoc Thanh Thi Nguyen - February 2026
