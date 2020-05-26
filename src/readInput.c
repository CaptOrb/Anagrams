#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extra.h"
#include "readInput.h"

extern const char *INPUT_PATH;

void readArray(char **inputArray, int lineCount) {

    unsigned lineNum = 0;

    FILE *fp = fopen(INPUT_PATH, "r");

    // If the file cannot be opened, alert the user
    if (fp == NULL) {
        perror("\nError opening input file");
        exit(EXIT_FAILURE);
    }

    while (lineNum < lineCount) {
        fgets(inputArray[lineNum], STRINGLEN + 2, fp);

        inputArray[lineNum][strcspn(inputArray[lineNum], "\n")] = '\0';
        inputArray[lineNum][strcspn(inputArray[lineNum], "\r")] = '\0';

        if(strlen(inputArray[lineNum]) > STRINGLEN){
            puts("A sentence in the input file had over 100 characters. Aborted.");
            exit(EXIT_FAILURE);
        }

        lineNum++;
    }

    fclose(fp);
}
