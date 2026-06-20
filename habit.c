#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Habit data type
typedef struct Habit {
    int best;
    int current;

    char name[24];
} Habit;

// create a new Habit
Habit new_habit() {
    // initialize
    Habit h; 
    h.best = 0;
    h.current = 0;

    // fill name
    printf("Enter habit name (ten characters or less): ");
    scanf("%10s", h.name);

    return h;
};


// displayed at execution
void greeting() {
    printf("Hello! Choose an option.\n"
        "1) Create new habit\n"
        "2) Exit\n");
};

int get_input() {
    //receive
    int x;
    scanf("%d", &x);

    //validate
    if (x < 0 || x > 10) { 
        return -1; //invalid input
    }
    else {
        return x;
    }
};
