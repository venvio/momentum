#ifndef HELPERS_H
#define HELPERS_H

void get_today(char today[], size_t size);
void flush(); // flushes stdin
char* get_string(void); // gets string from user
char **find_files(char *path);

#endif
