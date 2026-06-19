#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// habit data type
typedef struct habit {
    char *name;
    int best;
    int current;
} habit;

// declarations
habit *create_habit(char *name);
void greeting();

int main() {
    greeting();



    return 0;
};

// create a new habit
habit *create_habit(char *name) {
    habit *h = malloc(sizeof(habit));
    h->name = name;
    h->best = 0;
    h->current = 0;

    return h;
};

// displayed at execution

void greeting() {
    printf("Hello! Choose an option.\n"
        "1) Create new habit\n"
        "2) Exit\n");
};
