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

    if (opt < '1' || opt > '9') {
        return 1;
    }

    int option = opt - '0';
    *x = option;

    return 0;
}



// display stats from active habits
int dashboard() {
    // for reading dir
    struct dirent *de;

    // open directory
    DIR *dir = opendir(DATA_PATH);
    if (dir == NULL){
        printf("Failed to open %s\n", DATA_PATH);
        return -1;
    } 

    // read files in directory
    while ((de = readdir(dir)) != NULL) {
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) {
            continue;
        }

        printf("Habit: %s\n", de->d_name); // print habit name

        // get current
        char file[STR_LENGTH];
        snprintf(file, sizeof(file), "data/%s", de->d_name); // make full path
        struct tm *time0 = get_ref_date(file); // get reference date from habit within path
        int current = get_current(time0); // get current streak by subtracting ref date with current date
        free(time0);
        printf("Current Streak: %d\n", current);

        // get best
        int best = get_best(file);
        printf("Best Streak: %d\n", best);

        printf("\n"); // separate each habit by \n
    }

    closedir(dir);
    return 0;
}
