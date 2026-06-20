#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "habit.c"

int main() {
    bool flow = true;
    int input;

    // initial input block
    while (flow) {
        greeting();
        
        input = get_input();
        if (input > 0){
            flow = false;
        }
        else {
            printf("Invalid input. Enter integer corresponding to an option.\n");
            continue;
        }
    }

    printf("testing input against cases...\n");
    // test valid input against cases
    switch (input) {
        case 1: // create new Habit
            Habit habit;
            habit = new_habit();

            printf("Habit name: %s", habit.name);

        case 2:
            return 0; //exit
        default:
            printf("Unable to associate input with action.");
    }

    return 0;
};

