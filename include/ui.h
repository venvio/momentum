#ifndef UI_H
#define UI_H

void print_border(int length);
void print_header(const char *title);
void print_menu_item(const char *item);
void print_main_menu(void);
void clear_console(void);
void nap(int seconds); // sleep()
int print_dashboard(char habit[], int current, int best);
void habit_list(void); // prints a list of current habits

#endif
