#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ui.h"
#include "config.h"

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
    printf("| 4) Exit                        |\n");
    printf("+--------------------------------+\n");
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
