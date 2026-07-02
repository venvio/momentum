#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <regex.h>
#include <time.h>
#include "operations.h"


// searches the directory given by `char *path` and returns an array of files for up to 10 .csv files in the directory.
char **find_files(char *path) {
    char **files = malloc(11 * sizeof(char *)); // room for 10 files
    int i = 0; // for iterating over files

    // compile regex for '.csv'
    regex_t regx;
    int result = regcomp(&regx, ".*\\.csv$", REG_EXTENDED);
    if (result != 0) {
        printf("Failed to compile regex expression.\n");
        free(files);
        return NULL;
    }
    
    // for reading dir
    struct dirent *de;

    // open directory
    DIR *dir = opendir(path);
    if (dir == NULL){
        printf("Failed to open directory.\n");
        regfree(&regx);
        free(files);
        return NULL;
    } 


    // read files in directory
    while ((de = readdir(dir)) != NULL && i < 10) {
        result = regexec(&regx, de->d_name, 0, NULL, 0); // perform regex comparison here

       if (result == 0) { // match
            char *file = malloc(strlen(de->d_name) + 1);

            if (file == NULL){
                continue;
            }

            strcpy(file, de->d_name);
            files[i] = file; // add to array
            i++; // inc for next position
        }
    }

    // safe cleanup
    files[i] = NULL;
    regfree(&regx);
    closedir(dir);

    return files;
}

// increment streak value in given file
// format: 2026/06/26,1
int increment() {

    // get reference date

    // get today string
    char date[20];
    // raw time
    time_t raw_time = time(NULL);
    struct tm *local = localtime(&raw_time);
    // save to date string
    snprintf(date, sizeof(date),
            "%04d/%02d/%02d",
            local->tm_year + 1900,
            local->tm_mon + 1,
            local->tm_mday);

    // difference in days

    return 0;
}

