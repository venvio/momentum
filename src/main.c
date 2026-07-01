#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "operations.h"
#include "ui.h"

void flush();

int main() {
    bool running = true;

    // initial input block
    while (running) {
        print_header("Welcome to Lifestyle Counter!");
        print_main_menu();

       int opt = fgetc(stdin);
       flush();

        if (opt < '1' || opt > '4') {
            printf("Invalid input.\n");
            continue;
        }

        int option = opt - '0';

        printf("input: %d\n", option);

        // test valid input against cases
        switch (option) {
            case 1: {// create new Habit
                // fill name
                char name[11];
                printf("Enter habit name (ten characters or less): ");
                scanf("%10s", name);
                flush();

                if (create_habit(name) == 0){
                    printf("Habit successfully created!\n");
                } else {
                    printf("Failure during habit creation.\n");
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
                arr = find_files("data/"); // get array of files
                    
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
                    snprintf(path, sizeof(path), "data/%s.csv", input);
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
                arr = find_files("data/");

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
                if (dashboard() != 0) {
                    printf("Trouble printing dashboard");
                };
                break;
            }
            case 5: { 
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

// flush things from stdin buffer after inputs
void flush() {
    int ch;
    while ((ch = fgetc(stdin)) != '\n' && ch != EOF) {
        // discard the rest of the line
    }
}
