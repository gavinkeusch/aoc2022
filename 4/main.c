#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE* fp;
    
    fp = fopen("./input.txt", "r");
    // fp = fopen("./test.txt", "r");

    if (fp == NULL)
        exit(EXIT_FAILURE);

    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int count = 0;

    while ((read = getline(&line, &len, fp)) != -1) {
        int first = atoi(strsep(&line, "-"));
        int second = atoi(strsep(&line, ","));
        int third = atoi(strsep(&line, "-"));
        int fourth = atoi(strsep(&line, "-"));
        
        // PART 1
        // if ((first <= third && second >= fourth) || (third <= first && fourth >= second)) {
        //     count++;
        // }

        // PART 2
        for (int i = first; i <= second; i++) {
            if ((i >= third) && (i <= fourth)) {
                count++;
                break;
            } 
        }
    }

    printf("Total: %d\n", count);
}