#include <stdio.h>
#include <stdlib.h>

extern const char *OUTPUT_PATH;

void outputSortedWords(char ** inputArray, unsigned int lineCount) {

    FILE *fp = fopen(OUTPUT_PATH, "w+");

    // If the file cannot be opened, alert the user
    if (fp == NULL) {
        perror("\nError opening output file");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "The sorted list of words follows:\n\n");

    // print out the sentences which are now sorted alphabetically to the output file
    for (unsigned int i = 0; i < lineCount; i++)
        fprintf(fp, "%s\n", inputArray[i]);


    // close the output file
    fclose(fp);
}

void outputAnagram(char ** anagrams,  unsigned int x, unsigned int y,
        unsigned int groupsOfAnagrams){

    // open output file in append mode
    FILE *fp = fopen(OUTPUT_PATH, "a+");

    // If the file cannot be opened, alert the user
    if(fp == NULL) {
        perror("\nError opening output file");
        return;
    }

    if(groupsOfAnagrams == 1) {
        fputs( "\n\nAnagrams:\n\n", fp);
    }

    // print anagram to the output file
    fprintf(fp, "Anagram %u: %s %s\n", groupsOfAnagrams, anagrams[x], anagrams[y]);

    // close the file
    fclose(fp);
}
