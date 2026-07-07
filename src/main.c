#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "operations.h"
#include "menu.h"
#include "ui.h"

void flush();

int main() {
    bool running = true;

    // initial input block
    while (running) {
        print_header("Welcome to Lifestyle Counter!");
        print_main_menu();

        int option;
        if (get_option(option) != 0){
            printf("Invalid input.");
        };
        
        // test valid input against cases
        switch (option) {
            case 1: {
                if (create_habit() !=0) {
                    printf("Failed to create habit");
                };

                // save habit
                break;
            }

            case 2: {
                // delete_habit();
                break;
            }

            case 3: {
                // view_habits();
                break;
            }

            case 4: {
                // dashboard();
                break;
            }

            case 5: { 
                printf("Exiting...\n");
                running = false; //exit
                break;
            }

            default:{
                printf("Unable to associate input with action.");
            }
        }
    }

    return 0;
};

