#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int largest = 0;
    int current = 0;
    fp = fopen("./input.txt", "r");
    
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        int l = atoi(line);

        if (l != 0) {
            current += l;
        } else {
            if (current > largest) {
                largest = current;
            }
            current = 0;
        }  
    }

    printf("Largest Calories: %d\n", largest);

    fclose(fp);

    if (line)
        free(line);

    exit(EXIT_SUCCESS);  
}