#include <stdlib.h>
#include <stdio.h>
#include "ui.h"

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
    printf("| 1) Create new habit            |\n");
    printf("| 2) Delete habit                |\n");
    printf("| 3) Dashboard                   |\n");
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
