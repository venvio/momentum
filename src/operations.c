#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <regex.h>
#include <time.h>
#include "operations.h"

// create a new Habit
int create_habit(char *name) {
    // create file path
    char file[24] = "";
    char path[24] = "data/\0";
    
    strcat(file, name);
    strcat(file, ".csv");
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

// returns the best streak from a file
int get_best(char *file){
    FILE *fptr = fopen(file, "r");
    if (fptr == NULL) {
        printf("File failed to open\n");
        return 1;
    }

    int c; // read input
    bool swtch = false;
    int best = 0; 
    int num = 0; // to build multi-digit numbers

    // main loop
    while ((c = fgetc(fptr)) != EOF) {
        // if true, number of interest is in buffer
        if (swtch) { 
            if (c == '\n'){ // capture number, flush
                best = (num > best) ? num : best; // check if num is bigger
                num = 0;
                swtch = false;
                continue;
            } else if (c >= '0' && c <= '9') { // protect against reading header
                num = (num * 10) + c - '0';
                continue;
            }
        } 

        // numbers of interest will be next in buffer
        if (c == ',') {
            swtch = true;
            continue;
        }
    }

    fclose(fptr);
    return best;
}

int get_current(char *file) {
    FILE *fptr = fopen(file, "r");
    if (fptr == NULL) {
        printf("File failed to open\n");
        return 1;
    }

    int c; // read input
    bool swtch = false;
    int curr = 0; 
    int num = 0; // to build multi-digit numbers

    // main loop
    while ((c = fgetc(fptr)) != EOF) {
        // if true, number of interest is in buffer
        if (swtch) { 
            if (c == '\n'){ // capture number, flush
                curr = num; // assign current
                num = 0; // flush number
                swtch = false;
                continue;
            } else if (c >= '0' && c <= '9') { // protect against reading header
                num = (num * 10) + c - '0';
                continue;
            }
        } 

        // numbers of interest will be next in buffer
        if (c == ',') {
            swtch = true;
            continue;
        }
    }

    fclose(fptr);
    return curr;
}

// increment streak value in given file
// format: 2026/06/26,1
int increment(char *path) {
    printf("Path passed to increment: %s\n", path);
    int curr;
    curr = get_current(path); // get current streak
    printf("Curr returned from %s: %d\n", path, curr);

    FILE *fptr = fopen(path, "a"); // open file
    if (fptr == NULL) {
        printf("File failed to open\n");
        return 1;
    }

    // get date string
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

    // append new data
    fprintf(fptr, "%s,%d\n", date, (curr + 1));
    fclose(fptr);

    return 0;
}

// display stats from active habits
int dashboard() {
    // for reading dir
    struct dirent *de;

    // open directory
    DIR *dir = opendir("data/");
    if (dir == NULL){
        printf("Failed to open directory.\n");
        return 1;
    } 

    // read files in directory
    while ((de = readdir(dir)) != NULL)  {
        // skip over first two iterations
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) {
            continue;
        }

        // create path string
        char path[24] = "data/\0";
        strcat(path, de->d_name);
        printf("Full path: %s\n", path);
        
        int curr = get_current(path);
        int best = get_best(path);

        printf("%s\n", de->d_name);
        printf("Current: %d\n", curr);
        printf("Best: %d\n", best);
    }

    closedir(dir);
    return 0;
}
