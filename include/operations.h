#ifndef OPERATIONS_H
#define OPERATIONS_H

int create_habit(char *name);
char **find_files(char *path);
int get_best(char *file);
int get_current(char *file);
int increment(char *path);
int dashboard();

#endif
