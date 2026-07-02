#ifndef HABIT_H
#define HABIT_H
#include "config.h"

typedef struct Habit {
    char h_name[STR_LENGTH]; // name of the habit
    char init_date[STR_LENGTH]; // date user started tracking the habit
    bool reset; // if user has reset streak, this is `true`
    char reset_date[STR_LENGTH]; // if reset == true, this is new reference date
    int best; // best streak user has had for this habit
} Habit;

Habit* init_habit(char name[]);

#endif
