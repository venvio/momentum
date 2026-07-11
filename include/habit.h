#ifndef HABIT_H
#define HABIT_H
#include <time.h>
#include "config.h"

typedef struct Habit {
    char h_name[STR_LENGTH]; // name of the habit
    char init_date[STR_LENGTH]; // date user started tracking the habit
    bool reset; // if user has reset streak, this is `true`
    char reset_date[STR_LENGTH]; // if reset == true, this is new reference date
    int h_best; // best streak user has had for this habit
} Habit;

Habit* init_habit(void); // takes name as input and inits a Habit struct with default values
int save_habit(Habit* h); // save habit into data/ directory. uses habit name as file name
int delete_habit(void); // deletes a given habit from the directory DATA_PATH (defined in config.h)
struct tm* get_ref_date(char path[]); // used in get_current() as the reference date to be subtracted from current date.
int get_current(struct tm *time0); // returns the current streak for a given habit
int get_best(char path[]); // returns the best streak for a given habit

#endif
