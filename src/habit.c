#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Habit data type
typedef struct Habit {
    int best;
    int current;

    char name[24];
} Habit;

// create a new Habit
int init_habit(Habit *h) {
    // initialize
    h->best = 0;
    h->current = 0;

    // fill name
    printf("Enter habit name (ten characters or less): ");
    scanf("%10s", h->name);

    //initialize file
    char file[24];
    strcpy(file, h->name);

    char ext[5] = ".csv\0";
    strcat(file, ext);

    char path[11] = "../data/\0";
    strcat(path, file);
    printf("Full path: %s\n", path);

    // create file
    if (fopen(path, "r") != NULL) { // file already exists
        printf("File \"%s\" already exists.\n", path);
        return 1;

    } else if (fopen(path, "r") == NULL) { //create file
        FILE *fptr = fopen(path, "w");

        if (fptr == NULL) { // file creation failed
            printf("File creation for \"%s\" failed\n", path);
            return 1;
        } else { // file creation success
            fputs("Date,Streak\n", fptr); // insert template data 
            printf("Habit data created at \"%s\"\n", path);
            fclose(fptr);
        }
    }

    return 0;
};
