#include <stdio.h>
#include <string.h>

int main() {
    char s1[] = "Hello"; 
    char s2[] = "Geeks";

    // Concatenate str2 to str1
    strcat(s1, s2);

    printf("%s\n", s1);  
    return 0;
}
