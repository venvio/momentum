#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include "helpers.h"
#include "habit.h"
#include "config.h"

// get user's desired option
int get_option(int* x) {
   int opt = fgetc(stdin);
   flush();

    if (opt < '1' || opt > '4') {
        return 1;
    }

    int option = opt - '0';
    x = option;
    printf("input: %d\n", x);

    return 0;
}

// create habit
int create_habit() {
    // get name
    char name[STR_LENGTH];
    printf("Enter habit name: ");
    scanf("%23s", name);
    flush();

    Habit* habit = init_habit(name);

    if (habit == NULL){
        return 1;
    }

    return 0;
}

// save habit
int save_habit(Habit* h) {
    // create file path
    char file[STR_LENGTH] = "";
    char path[STR_LENGTH] = "data/\0";
    
    strcat(file, name);
    strcat(file, ".txt");
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
            printf("Habit data created at \"%s\"\n", path);
            fclose(fptr);
        }
    }

    return 0;
};

// display stats from active habits
int dashboard() {

    return 0;
}
