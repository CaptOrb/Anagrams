#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "extra.h"
#include "readInput.h"

extern const char *INPUT_PATH;

void readArray(char **inputArray, int lineCount) {

    unsigned lineNum = 0;
    bool lineTooLong = false;

    FILE *fp = fopen(INPUT_PATH, "r");

    // If the file cannot be opened, alert the user
    if (fp == NULL) {
        perror("\nError opening input file");
        exit(EXIT_FAILURE);
    }

    while (lineNum < lineCount) {

        if (fgets(inputArray[lineNum], STRINGLEN + 2, fp) != NULL) {

            inputArray[lineNum][strcspn(inputArray[lineNum], "\n")] = '\0';
            inputArray[lineNum][strcspn(inputArray[lineNum], "\r")] = '\0';

            if(strlen(inputArray[lineNum]) > STRINGLEN){
                lineTooLong = true;
                continue;
            }

            lineNum++;
        }
    }
    fclose(fp);

    if(lineTooLong) {
        fputs("\nA sentence in the input file has more than 100"
              " characters and has been ignored\n", stderr);
    }
}
