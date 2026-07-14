#include "common.h"

int main() {
    bool running = true;

    // initial input block
    while (running) {
        clear_console();

        print_header("Momentum: A Lifestyle Counter");
        print_main_menu();

        int option;
        if (get_option(&option) != 0) {
            printf("Invalid input.");
            continue;
        };
        
        // test valid input against cases
        switch (option) {
            case 1: {
                if (dashboard() != 0) {
                    printf("Failed to launch dashboard.\n");
                }

                break;
            }

            case 2: {
                Habit* h = init_habit();
                if (h == NULL) {
                    printf("Habit creation failed.");
                }
               
                if (save_habit(h) != 0) { // save habit
                    printf("Failed to save habit.");
                };

                break;
            }

            case 3: {
                if (delete_habit() != 0) {
                    printf("Failed to delete habit.\n");
                }

                break;
            }

            case 4: { 
                if (reset_streak() != 0) {
                    printf("Failed to reset streak.\n");
                }

                break;
            }

            case 5: { 
                printf("Exiting...\n");
                return 0;
            }

            default:{
                printf("Unable to associate input with action.");
            }
        }

        printf("\n(Press Enter to continue...)");
        fflush(stdout);

        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
            //discard rest of line
        }
    }

    return 0;
};

