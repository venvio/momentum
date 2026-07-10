#include <unistd.h>
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
        clear_console();

        print_header("Momentum: A Lifestyle Counter");
        print_main_menu();

        int option;
        if (get_option(&option) != 0){
            printf("Invalid input.");
        };
        
        // test valid input against cases
        switch (option) {
            case 1: {
                printf("Habit name: \n");
                char* name = get_string();
                Habit* h = init_habit(name);
                if (h == NULL){
                    printf("Habit creation failed.");
                }
                // save habit
                if (save_habit(h) != 0){
                    printf("Failed to save habit.");
                };

                break;
            }

            case 2: {
                printf("Delete which habit?: \n");
                char* filename = get_string();

                if (delete_habit (filename) != 0){
                    printf("Failed to delete habit.\n");
                }

                break;
            }

            case 3: {
                dashboard();
                break;
            }

            case 4: { 
                printf("Exiting...\n");
                running = false; //exit
                return 0;
            }

            default:{
                printf("Unable to associate input with action.");
            }
        }

        printf("\n(Press Enter to continue)");
        fflush(stdout);

        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF){
            //discard rest of line
        }
    }

    return 0;
};

