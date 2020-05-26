#include <stdio.h>
#include <stdlib.h>
#include "readInput.h"
#include "outputResults.h"
#include "anagram.h"
#include "extra.h"
#include "sort.h"

const char *INPUT_PATH = "../inputFiles/input.txt";

const char *OUTPUT_PATH = "../output.txt";

int main() {

    int lineCount = getLineCount();

    char **inputArray = calloc(lineCount , sizeof(inputArray));

    if (inputArray == NULL) {
        return EXIT_FAILURE;
    }

    for (unsigned int i = 0; i < lineCount; i++) {
        inputArray[i] =  calloc(STRINGLEN + 2 , sizeof(char));
    }

    // Call function to read in a list of sentences from input file and place them in 2D array of characters
    readArray(inputArray, lineCount);

    // call quick sort function to sort strings alphabetically
    quicksort(inputArray, 0, lineCount - 1);

    // call function to output the sorted words
    outputSortedWords(inputArray, lineCount);

    // call function to check which words are anagrams
    findAnagrams(inputArray, lineCount);

   for (unsigned int i = 0; i < lineCount; i++){
       free(inputArray[i]);
   }
   free(inputArray);

   return EXIT_SUCCESS;
}

 int getLineCount(){
     int count = 0;

    FILE *fp = fopen(INPUT_PATH, "r+");

    if (fp == NULL) {
        perror("\nError opening input file");
        exit(EXIT_FAILURE);
    }

    for (int c = getc(fp); c != EOF; c = getc(fp)) {
        if (c == '\n')
            count++;
    }

    fclose(fp);

     if(count == 0){
         printf("The input file is empty");
         exit(EXIT_FAILURE);
     }

     return count + 1;
}