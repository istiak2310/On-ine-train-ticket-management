#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"
#include "splashcreen.h"

#define MAX_TRAINS 100
#define MAX_PASSENGERS 500



// Structure to store train information
typedef struct {
    int trainNumber;
    char source[50];
    char destination[50];
    int seatsAvailable;
} Train;

// Structure to store passenger information
typedef struct {
    int ticketNumber;
    char name[50];
    int trainNumber;
} Passenger;

// Global arrays to store train and passenger information
Train trains[MAX_TRAINS];
Passenger passengers[MAX_PASSENGERS];
int trainCount = 0;
int passengerCount = 0;

// Function to initialize train data
void initializeTrains() {
    trains[trainCount].trainNumber = 1;
    strcpy(trains[trainCount].source, "Source1");
    strcpy(trains[trainCount].destination, "Destination1");
    trains[trainCount].seatsAvailable = 50;
    trainCount++;

    trains[trainCount].trainNumber = 2;
    strcpy(trains[trainCount].source, "Source2");
    strcpy(trains[trainCount].destination, "Destination2");
    trains[trainCount].seatsAvailable = 40;
    trainCount++;

    // Add more trains as needed
}

// Function to display available trains
void displayTrains() {
    printf("Available Trains:\n");
    printf("Train No.\tSource\t\tDestination\tSeats Available\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < trainCount; i++) {
        printf("%d\t\t%s\t\t%s\t\t%d\n", trains[i].trainNumber, trains[i].source, trains[i].destination, trains[i].seatsAvailable);
    }
    printf("--------------------------------------------------\n");
}

// Function to check seat availability
int checkSeatAvailability(int trainNumber) {
    for (int i = 0; i < trainCount; i++) {
        if (trains[i].trainNumber == trainNumber) {
            return trains[i].seatsAvailable;
        }
    }
    return 0;
}

// Function to book a ticket
void bookTicket() {
    int trainNumber, seats;
    char passengerName[50];

    printf("Enter Train Number: ");
    scanf("%d", &trainNumber);
    printf("Enter Passenger Name: ");
    scanf("%s", passengerName);
    printf("Enter Number of Seats: ");
    scanf("%d", &seats);

    int availableSeats = checkSeatAvailability(trainNumber);
    if (availableSeats >= seats) {
        trains[trainNumber - 1].seatsAvailable -= seats;

        passengers[passengerCount].ticketNumber = passengerCount + 1;
        passengers[passengerCount].trainNumber = trainNumber;
        strcpy(passengers[passengerCount].name, passengerName);
        passengerCount++;

        printf("\nTicket Booked Successfully!\n");
        printf("Ticket Number: %d\n", passengerCount);
        printf("Passenger Name: %s\n", passengerName);
        printf("Train Number: %d\n", trainNumber);
        printf("Number of Seats: %d\n", seats);
    } else {
        printf("\nSorry! Seats not available.\n");
    }
}

// Function to cancel a ticket
void cancelTicket() {
    int ticketNumber;
    printf("Enter Ticket Number: ");
    scanf("%d", &ticketNumber);

    if (ticketNumber > 0 && ticketNumber <= passengerCount) {
        int trainNumber = passengers[ticketNumber - 1].trainNumber;
        int seats;
        printf("Enter Number of Seats to Cancel: ");
        scanf("%d", &seats);

        trains[trainNumber - 1].seatsAvailable += seats;

        printf("\nTicket Canceled Successfully!\n");
    } else {
        printf("\nInvalid Ticket Number.\n");
    }
}

// Function to display the main menu
void displayMenu() {
    printf("\n********* Railway Ticket Management **********\n");
    printf("1. Display Available Trains\n");
    printf("2. Check Seat Availability\n");
    printf("3. Book a Ticket\n");
    printf("4. Cancel a Ticket\n");
    printf("5. Exit\n");
    printf("************************************************\n");
    printf("Enter your choice: ");
}

int main() {
    splash_screen();

    int choice;
    printf("\n\t\t\tWelcome to registration and login page***");
    printf("\n\n\nChoose your option:\n");
    printf("1. Registration \n2. Login\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        system("CLS");
        registe();
    }
    else if(choice==2)
    {
        system("CLS");
        login();
        system("CLS");
    }
    else
    {
        printf("Invalid choice..");
    }

    initializeTrains();


    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayTrains();
                break;
            case 2:
                // Implement seat availability functionality
                break;
            case 3:
                bookTicket();
                break;
            case 4:
                cancelTicket();
                break;
            case 5:
                printf("Thank you for using the Railway Ticket Management System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

