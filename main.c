
#define _CRT_SECURE_NO_WARNINGS  // Disable Visual Studio security warnings
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, char* argv[]) {
    int numUsers;
    
    // STEP 1: Get user input (command line or interactive)
    // Check if command line argument is provided
    if (argc == 2) {
        // Use command line argument
        numUsers = atoi(argv[1]);
    }
    else {
        // Prompt user for input
        printf("Enter the number of users to add to the queue: ");
        scanf("%d", &numUsers);
    }
    
    // Validate input
    if (numUsers <= 0) {
        printf("Error: Number of users must be a positive integer.\n");
        return 1;
    }

    // STEP 2: Initialize empty queue (head = NULL, tail = NULL)
    Queue q;
    initializeQueue(&q);
    printf("Queue initialized successfully.\n");

    // STEP 3: Add random users to queue (enqueue operation)
    // Each user gets random username, level (1-60), and faction
    printf("\nAdding %d random users to the queue...\n", numUsers);
    if (addRandomUsers(&q, numUsers) != 0) {
        printf("Error: Failed to add users to the queue.\n");
        return 1;
    }
    printf("Successfully added %d users to the queue.\n", numUsers);

    // STEP 4: Demonstrate FIFO behavior - dequeue all users
    // Users will be removed in the same order they were added
    printf("\n=== Dequeuing all users ===\n");
    printf("-----------------------------------------------------------\n");

    int userCount = 0;
    while (!isQueueEmpty(&q)) {
        User u = dequeue(&q);  // Remove from front (FIFO)
        userCount++;

        // Display user information
        printf("User #%d:\n", userCount);
        printf("  Username: %s\n", u.username);
        printf("  Level:    %d\n", u.level);
        printf("  Faction:  ");

        // Display faction name based on enum value
        if (u.faction == RED)   printf("Red\n");
        else if (u.faction == BLUE)  printf("Blue\n");
        else if (u.faction == GREEN) printf("Green\n");

        printf("-----------------------------------------------------------\n");
    }

    printf("\nAll users have been dequeued. Queue is now empty.\n");
    return 0;
}
