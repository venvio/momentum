#include "common.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void print_border(int length) {
    printf("*");
    for (int i = 0; i < length; i++) {
        printf("-");
    }
    printf("*\n");
}

void print_menu_item(const char *item) {
    int width = BORDER_LENGTH - 1;

    printf("| %-*s|\n", width, item);
}

void print_header(const char *title) {
    print_border(BORDER_LENGTH);
    print_menu_item(title);
    print_border(BORDER_LENGTH);
}

void print_main_menu(void) {
    print_menu_item("1) Dashboard");
    print_menu_item("2) New Habit");
    print_menu_item("3) Delete Habit");
    print_menu_item("4) Reset Streak");
    print_menu_item("5) Exit");
    print_border(BORDER_LENGTH);
    printf("Choose an option: ");
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
    DIR *dir = opendir(HABIT_PATH);

    if (dir == NULL){
        printf("Failed to open %s\n", HABIT_PATH);
    } 

    print_header("Saved Habits");
    while ((de = readdir(dir)) != NULL) { // iterate over files in dir
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) { // skip over sys directory entries
            continue;
        }

        printf("|•%.*s\n", (int)strlen(de->d_name) - 4, de->d_name);
    }
    print_border(BORDER_LENGTH);

    closedir(dir);
}
