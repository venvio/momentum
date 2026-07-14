#include "common.h"

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

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return NULL;
    }

    buffer[strcspn(buffer, "\n")] = '\0'; // replace \n with \0
    
    char* str = malloc(strlen(buffer) + 1);
    if (str == NULL){
        return NULL;
    }

    strcpy(str, buffer);

    return str;
}

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
