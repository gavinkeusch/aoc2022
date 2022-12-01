#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE* fp;
    
    fp = fopen("./input.txt", "r");
    
    if (fp == NULL)
        exit(EXIT_FAILURE);

    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int first = 0;
    int second = 0;
    int third = 0;
    int total = 0;

    while ((read = getline(&line, &len, fp)) != -1) {
        int current = atoi(line);

        if (current != 0) {
            total += current;
        } else {
            if (total > first) {
                third = second;
                second = first;
                first = total;
            } else if (total > second) {
                third = second;
                second = total;
            } else if (total > third) {
                third = total;
            }
            total = 0;
        }  
    }

    printf("Largest 3 Calories: %d, %d, %d\n", first, second, third);
    printf("Total: %d\n", first + second + third);

    fclose(fp);

    if (line)
        free(line);

    exit(EXIT_SUCCESS);  
}