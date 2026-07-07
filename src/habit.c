#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "helpers.h"
#include "config.h"

typedef struct Habit {
    char h_name[STR_LENGTH]; // name of the habit
    char init_date[STR_LENGTH]; // date user started tracking the habit
    bool reset; // if user has reset streak, this is `true`
    char reset_date[STR_LENGTH]; // if reset == true, this is new reference date
    int h_best; // best streak user has had for this habit
} Habit;

// initialize new habit
Habit* init_habit(char name[]) {
    Habit* h = malloc(sizeof(Habit));

    if (h == NULL){
        return NULL;
    }

    // get date
    char today[STR_LENGTH];
    get_today(today, sizeof(today));

    // fills Habit members
    strcpy(h->h_name, name);
    strcpy(h->init_date, today);
    h->reset = false;
    h->h_best = 0;

    return h;
}

// save habit
int save_habit(Habit* h) {
    // create file path
    char path[STR_LENGTH];

    snprintf(path, sizeof(path), "data/%s.txt", h->h_name);

    printf("Full path: %s\n", path);

    // check if file already exists
    FILE *check = fopen(path, "r");
    if (check != NULL) {
        fclose(check);
        printf("File \"%s\" already exists.\n", path);

        return 1;
    }

    FILE *fptr = fopen(path, "w");
    if (fptr == NULL) { // file creation failed
        printf("File creation for \"%s\" failed\n", path);

        return 1;
        }  

    // add template data
    fprintf(fptr, "h_name:%s\n", h->h_name);
    fprintf(fptr, "init_date:%s\n", h->init_date);
    fprintf(fptr, "reset:%d\n", h->reset);
    fprintf(fptr, "reset_date:\n");
    fprintf(fptr, "best:%d\n", h->h_best);
    fclose(fptr);

    printf("Habit data created at \"%s\"\n", path);

    return 0;
};

