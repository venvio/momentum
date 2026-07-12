#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <assert.h>
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

// dashboard which displays stats from active habits
int dashboard() {
    struct dirent *de; // for reading dir
    DIR *dir = opendir(DATA_PATH); // open directory

    if (dir == NULL){ // check if directory failed to open
        printf("Failed to open %s\n", DATA_PATH);
        return 1;
    } 
    
    while ((de = readdir(dir)) != NULL) { // iterate over files in dir
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) { // skip over sys directory entries
            continue;
        }

        char file[STR_LENGTH]; // make full path
        snprintf(file, sizeof(file), "data/%s", de->d_name); 

        // get current and best streaks
        struct tm *time0 = get_ref_date(file);
        int current = get_current(time0);
        int best = get_best(file); 

        // check if current streak is better than recorded best
        if (current >= best) {
            update_best(file, current);
            best = get_best(file);
            print_dashboard(de->d_name, current, best);
        }
        else { print_dashboard(de->d_name, current, best); }
    }

    closedir(dir);
    return 0;
}
