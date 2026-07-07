#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "helpers.h"
#include "menu.h"
#include "ui.h"

int main() {
    bool running = true;

    // initial input block
    while (running) {
        print_header("Welcome to Lifestyle Counter!");
        print_main_menu();

        int option;
        if (get_option(&option) != 0){
            printf("Invalid input.");
        };
        
        printf("option: %d", option);
        // test valid input against cases
        switch (option) {
            case 1: {

                char* name = get_string();

                if (init_habit(name) !=0) {
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

