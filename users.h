#include <stdio.h>
#include <stdlib.h>

struct User {
    char username[50];
    char password[50];
};

void registerUser(struct User users[], int *userCount);
int loginUser(struct User users[], int userCount, char *username,char *password);






