#include <stdio.h>
#include "ui.h"

void print_header(const char *title) {
    printf("\n+--------------------------------+\n");
    printf("| %-30s |\n", title);
    printf("+--------------------------------+\n");
}

void print_main_menu(void) {
    print_header("HABIT TRACKER");
    printf("| 1) Create new habit            |\n");
    printf("| 2) Delete habit                |\n");
    printf("| 3) View habits                 |\n");
    printf("| 4) Dashboard                   |\n");
    printf("| 5) Exit                        |\n");
    printf("+--------------------------------+\n");
    printf("Choose an option: ");
}
