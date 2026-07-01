#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include "operations.h"

int main() {
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

        if (increment(path) == 0) { // increment file
            printf("File %s incremented successfully.\n", path);
        } else {
            printf("Failure incrementing %s\n", path);
        }
    }

    closedir(dir); // close dir
    return 0;
}
