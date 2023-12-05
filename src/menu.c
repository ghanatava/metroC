#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"
#include "../include/graph.h"

// Function to display the main menu

int menu() {
    int choice;
    printf("                __                            \n");
    printf("  _____   _____/  |________  ____      ____   \n");
    printf(" /     \\_/ __ \\   __\\_  __ \\/  _ \\   _/ ___\\  \n");
    printf("|  Y Y \\  ___/|  |  |  | \\(  <_> )  \\  \\___  \n");
    printf("|__|_|  /\\___  >__|  |__|  \\____/____\\___  > \n");
    printf("     \\/     \\/                 /_____/   \\/  \n");
    while (1) {
        displayMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Displaying Metro Map...\n");
                map();
                break;
            case 2:
                int source, destination;
                printf("\nEnter source between 0 to 4: ");
                scanf("%d",&source);
                printf("\nEnter destination between 0 to 4: ");
                scanf("%d",&destination);

                if(source < 0 || source > 4 || destination < 0 || destination > 4 ){
                    printf("entere a valid choice between stations 0 to 4");
                    break;
                }

                printf("Finding Shortest Route...\n");
                dijkstra_caller(source,destination);
                break;
            case 3:
                printf("Buying a Ticket...\n");
                // Implement ticket purchase functionality here
                break;
            case 4:
                printf("Exiting the GMRC Metro System CLI. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

