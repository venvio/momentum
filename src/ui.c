#include "common.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void print_header(const char *title) {
    printf("\n+--------------------------------+\n");
    printf("| %-30s |\n", title);
    printf("+--------------------------------+\n");
}

void print_main_menu(void) {
    print_header("Options:");
    printf("| 1) Dashboard                   |\n");
    printf("| 2) New Habit                   |\n");
    printf("| 3) Delete Habit                |\n");
    printf("| 4) Reset a Streak :(           |\n");
    printf("| 5) Exit                        |\n");
    printf("+--------------------------------+\n");
    printf("Choose an option: ");
}

void print_border(void) {
    printf("+--------------------------------+\n");
}

void clear_console(void) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void nap(int seconds) {
    #ifdef _WIN32
        Sleep(seconds * 1000);
    #else
        sleep(seconds);
    #endif
}

int print_dashboard(char habit[], int current, int best){
    printf("Habit: " ANSI_CYAN "%.*s" COLOR_RESET "\n", (int)strlen(habit) - 4, habit);
    printf("Current Streak: " ANSI_RED "%d" COLOR_RESET "\n", current);
    printf("Best Streak: " ANSI_GREEN "%d" COLOR_RESET "\n", best);
    printf("\n");

    return 0;
}

void habit_list(void) {
    struct dirent *de;
    DIR *dir = opendir(DATA_PATH);

    if (dir == NULL){
        printf("Failed to open %s\n", DATA_PATH);
        return 1;
    } 

    print_header("Saved Habits");
    while ((de = readdir(dir)) != NULL) { // iterate over files in dir
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) { // skip over sys directory entries
            continue;
        }

        printf("|•%.*s                       |\n", (int)strlen(de->d_name) - 4, de->d_name);
    }
    print_border();

    closedir(dir);
    return 0;
}
