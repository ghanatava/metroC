#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/users.h"
#include "../include/menu.h"

// Define the maximum number of users
#define MAX_USERS 100

// Structure to represent a user


// Function to register a new user
void registerUser(struct User users[], int *userCount) {
    if (*userCount >= MAX_USERS) {
        printf("User limit reached. Cannot register more users.\n");
        return;
    }

    struct User newUser;
    printf("Enter a username: ");
    scanf("%s", newUser.username);

    // Check if the username already exists
    for (int i = 0; i < *userCount; i++) {
        if (strcmp(newUser.username, users[i].username) == 0) {
            printf("Username already exists. Please choose a different one.\n");
            return;
        }
    }

    printf("Enter a password: ");
    scanf("%s", newUser.password);

    // Add the new user to the array
    users[*userCount] = newUser;
    (*userCount)++;

    // Store user data in a text file
    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Failed to open the user data file.\n");
        return;
    }
    fprintf(file, "%s %s\n", newUser.username, newUser.password);
    fclose(file);

    printf("User registered successfully!\n");
}

// Function to authenticate a user
int loginUser(struct User users[], int userCount, char *username, char *password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            return i; // Return the index of the authenticated user
        }
    }
    return -1; // User not found
}


void displayMainMenu() {
    printf("GMRC Metro System\n");
    printf("1. View Map\n");
    printf("2. Find Shortest Route\n");
    printf("3. Buy Ticket\n");
    printf("4. Exit\n");
}




int main() {
    struct User users[MAX_USERS];
    int userCount = 0;

    // Load user data from the text file
    FILE *file = fopen("users.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%s %s", users[userCount].username, users[userCount].password) != EOF) {
            userCount++;
        }
        fclose(file);
    }

    int choice;
    do {
        printf("\n1. Register\n2. Login\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser(users, &userCount);
                break;
            case 2:
                char username[50];
                char password[50];
                printf("Enter your username: ");
                scanf("%s", username);
                printf("Enter your password: ");
                scanf("%s", password);
                int userIndex = loginUser(users, userCount, username, password);
                if (userIndex >= 0) {
                    printf("Login successful! Welcome, %s.\n", users[userIndex].username);
                    menu();
                } else {
                    printf("Login failed. Invalid username or password.\n");
                }
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
