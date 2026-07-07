#ifndef MENU_H
#define MENU_H
#include "habit.h"

int get_option(int x);
int init_habit(char* name, char* date);
int save_habit(Habit* h);
int dashboard();

#endif
