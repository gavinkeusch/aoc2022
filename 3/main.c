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
    int score = 0;

    char* line1 = NULL;
    int len1, len2;
    char* line2 = NULL;
    int count = 1;

    while ((read = getline(&line, &len, fp)) != -1) {
        // PART 1
        // int len1 = read / 2;
        // int len2 = read - len1;

        // char* first = malloc(len1 + 1);
        // char* second = malloc(len2 + 1);

        // memcpy(first, line, len1);
        // first[len1] = '\0';

        // memcpy(second, line + len1, len2);
        // second[len2] = '\0';

        // char d;

        // for (int i = 0; i < len1; i++) {
        //     for (int j = 0; j < len2; j++) {
        //         if (first[i] == second[j]) {
        //             d = first[i];
        //             break;
        //         } 
        //     }
        // }

        // PART 2
        if (count == 1) {
            len1 = (int)read;
            line1 = malloc(len);
            strcpy(line1, line);
            count++;
        } else if (count == 2) {
            len2 = (int)read;
            line2 = malloc(len);
            strcpy(line2, line);
            count++;
        } else {
            char d;

            for (int i = 0; i < len1 - 1; i++) {
                for (int j = 0; j < len2 - 1; j++) {
                    for (int k = 0; k < read - 1; k++) {
                        if (line1[i] == line2[j] && line1[i] == line[k]) {
                            d = line1[i];
                            break;
                        }
                    }
                }
            }

            int v = (int)d;

            if (v >= 65 && v <= 90) {
                v -= 64;
                v += 26;
                score += v;
            } else {
                v -= 96;
                score += v;
            }

            count = 1;
            free(line1);
            free(line2);
        }

    }

    printf("Total: %d\n", score);
}