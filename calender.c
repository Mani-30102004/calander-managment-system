#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for calendar events
struct Event {
    char date[11];  // Date in the format "YYYY-MM-DD"
    char title[100];
};

// Define a dynamic array to store events
struct Event* events = NULL;
int numEvents = 0;

// Function to add an event to the calendar
void addEvent(char date[], char title[]) {
    struct Event newEvent;
    strcpy(newEvent.date, date);
    strcpy(newEvent.title, title);

    // Allocate memory for the new event
    if (events == NULL) {
        events = (struct Event*)malloc(sizeof(struct Event));
    } else {
        events = (struct Event*)realloc(events, (numEvents + 1) * sizeof(struct Event));
    }

    if (events == NULL) {
        printf("Memory allocation failed. Unable to add event.\n");
        return;
    }

    events[numEvents] = newEvent;
    numEvents++;
}

// Function to display all events on a specific date
void displayEventsOnDate(char date[]) {
    printf("Events on %s:\n", date);
    for (int i = 0; i < numEvents; i++) {
        if (strcmp(events[i].date, date) == 0) {
            printf("%s: %s\n", events[i].date, events[i].title);
        }
    }
}

// Function to display all events in the calendar
void displayAllEvents() {
    printf("All Events in the Calendar:\n");
    for (int i = 0; i < numEvents; i++) {
        printf("%s: %s\n", events[i].date, events[i].title);
    }
}

// Function to free memory and exit the program
void cleanup() {
    free(events);
    exit(0);
}

int main() {
    while (1) {
        printf("\nCalendar Management Menu:\n");
        printf("1. Add Event\n");
        printf("2. Display Events on a Date\n");
        printf("3. Display All Events\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                char date[11];
                char title[100];
                printf("Enter event date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter event title: ");
                getchar();  // Clear the newline character from the input buffer
                fgets(title, sizeof(title), stdin);
                addEvent(date, title);
                break;

            case 2:
                printf("Enter date to display events (YYYY-MM-DD): ");
                char dateToDisplay[11];
                scanf("%s", dateToDisplay);
                displayEventsOnDate(dateToDisplay);
                break;

            case 3:
                displayAllEvents();
                break;

            case 4:
                cleanup();

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
