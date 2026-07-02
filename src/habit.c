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
    int best; // best streak user has had for this habit
} Habit;

// initialize new habit
Habit* init_habit(char name[]) {
    Habit* habit = malloc(sizeof(Habit));

    if (habit == NULL){
        return NULL;
    }

    strcpy(habit->h_name, name);

    char today[STR_LENGTH];
    get_today(today, sizeof(today));

    strcpy(habit->init_date, today);

    habit->reset = false;
    habit->best = 0;

    return habit;
}

