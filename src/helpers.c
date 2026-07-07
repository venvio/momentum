#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "config.h"

// gets the date from system
void get_today(char today[], size_t size) {
    // raw time
    time_t raw_time = time(NULL);
    struct tm *local = localtime(&raw_time);

    // save to date string
    snprintf(today, size,
            "%04d/%02d/%02d",
            local->tm_year + 1900,
            local->tm_mon + 1,
            local->tm_mday);
}

// flush things from stdin buffer after inputs
void flush() {
    int ch;
    while ((ch = fgetc(stdin)) != '\n' && ch != EOF) {
        // discard the rest of the line
    }
}

char* get_string(void) {
    char buffer[STR_LENGTH];

    if (fgets(buffer, sizeof(buffer), stdin) == NULL){
        return NULL;
    }
    
    flush();
    
    char* str = malloc(strlen(buffer) + 1);
    if (str == NULL){
        return NULL;
    }

    strcpy(str, buffer);

    return str;
}
