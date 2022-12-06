#include <stdio.h>
#include <stdlib.h>

#define E_ROCK     'A'
#define E_PAPER    'B'
#define E_SCISSORS 'C'

#define M_ROCK     'X'
#define M_PAPER    'Y'
#define M_SCISSORS 'Z'

#define LOSE 0
#define DRAW 3
#define WIN  6

#define ROCK     1
#define PAPER    2
#define SCISSORS 3

#define M_LOSE 'X'
#define M_DRAW 'Y'
#define M_WIN  'Z'

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

    while ((read = getline(&line, &len, fp)) != -1) {
        char e = line[0]; // enemy
        char m = line[2]; // me
        

        // PART 1
        // if (e == E_ROCK) {
        //     if (m == M_ROCK) {
        //         score += ROCK + DRAW;
        //     } else if (m == M_PAPER) {
        //         score += PAPER + WIN;
        //     } else {
        //         score += SCISSORS + LOSE;
        //     }
        // } else if (e == E_PAPER) {
        //     if (m == M_ROCK) {
        //         score += ROCK + LOSE;
        //     } else if (m == M_PAPER) {
        //         score += PAPER + DRAW;
        //     } else {
        //         score += SCISSORS + WIN;
        //     }
        // } else {
        //     if (m == M_ROCK) {
        //         score += ROCK + WIN;
        //     } else if (m == M_PAPER) {
        //         score += PAPER + LOSE;
        //     } else {
        //         score += SCISSORS + DRAW;
        //     }
        // }

        // PART 2
        if (m == M_LOSE) {
            score += LOSE;

            if (e == E_ROCK) {
                score += SCISSORS;
            } else if (e == E_PAPER) {
                score += ROCK;
            } else {
                score += PAPER;
            }
        } else if (m == M_DRAW) {
            score += DRAW;

            if (e == E_ROCK) {
                score += ROCK;
            } else if (e == E_PAPER) {
                score += PAPER;
            } else {
                score += SCISSORS;
            }
        } else {
            score += WIN;

            if (e == E_ROCK) {
                score += PAPER;
            } else if (e == E_PAPER) {
                score += SCISSORS;
            } else {
                score += ROCK;
            }
        }
    }

    printf("Total Score: %d\n", score);
}