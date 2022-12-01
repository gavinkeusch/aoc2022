#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int l1 = 0;
    int l2 = 0;
    int l3 = 0;
    int current = 0;
    fp = fopen("./input.txt", "r");
    
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        int l = atoi(line);

        if (l != 0) {
            current += l;
        } else {
            if (current > l1) {
                l3 = l2;
                l2 = l1;
                l1 = current;
            } else if (current > l2) {
                l3 = l2;
                l2 = current;
            } else if (current > l3) {
                l3 = current;
            }
            current = 0;
        }  
    }

    printf("Largest 3 Calories: %d, %d, %d\n", l1, l2, l3);
    printf("Total: %d\n", l1 + l2 + l3);

    fclose(fp);

    if (line)
        free(line);

    exit(EXIT_SUCCESS);  
}