#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "habit.c"
#include "file.c"

int main() {
    bool running = true;
    int input;

    // initial input block
    while (running) {
        printf("\nHello! Choose an option.\n"
        "1) Create new habit\n"
        "2) Delete habit\n"
        "3) View habits\n"
        "4) Exit\n");

        //receive input
        scanf("%d", &input);
        getchar(); // consume trailing \n?

        //validate
        if (input < 0 || input > 10) { 
            return -1; //invalid input
        }

        // test valid input against cases
        switch (input) {
            case 1: {// create new Habit
                Habit *habit = malloc(sizeof(Habit));

                if (init_habit(habit) == 0){
                    printf("Habit successfully created!\n");
                    free(habit);

                } else {
                    printf("Failure during habit creation.\n");
                    free(habit);
                };

                break;
            }
            case 2: {// delete habit
                char input[100];
                printf("Type the name of the habit you want to delete: ");

                fgets(input, sizeof(input), stdin);
                // remove \n
                input[strcspn(input, "\n")] = '\0';

                // ensure it was a valid file
                char **arr;
                arr = find_files("../data/"); // get array of files
                    
                // search for file match
                bool found = false;

                for (int i = 0; arr[i] != NULL; i++) {
                    if (strstr(arr[i], input) != NULL) {
                        found = true;
                        free(arr[i]);
                        break;
                    }
                    free(arr[i]);
                }

                // check if match was found
                if (found) {
                    printf("File for deletion was found.\n"); 
                    char path[100];
                    snprintf(path, sizeof(path), "../data/%s.csv", input);
                    if (remove(path) == 0){// deletion successful
                        printf("Habit data at \"%s\" was successfully deleted.\n", path);
                    }; 
                } else {
                    printf("No data for \"%s\" exists.\n", input);
                }

                free(arr);
                break;
            }
            case 3: {// view all
                char **arr;
                arr = find_files("../data/");

                if (arr[0] == NULL){
                    printf("No data exists.\n");
                }

                printf("\nExisting habit data:\n");
                // print file list
                for (int i = 0; arr[i] != NULL; i++) {
                    printf("%d) %s\n", i+1, arr[i]);
                    free(arr[i]);
                }

                free(arr);
                break;
            }
            case 4: { 
                printf("Exiting...\n");
                running = false; //exit
                break;
            default:
                printf("Unable to associate input with action.");
            }
        }
    }
    return 0;
};
