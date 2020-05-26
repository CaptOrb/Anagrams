#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "anagram.h"
#include "outputResults.h"

#define LETTERSINALPHABET 26

void findAnagrams(char **inputArray, int lineNum) {

    unsigned int lengthString[lineNum], groupsOfAnagrams = 0;
    unsigned int **charCount = calloc(lineNum , sizeof(charCount));

    for (unsigned int p = 0; p < lineNum; p++) {
        lengthString[p] = 0;
        charCount[p] = calloc(LETTERSINALPHABET , sizeof(int));

        for (unsigned int j = 0; inputArray[p][j] != '\0'; j++) {

            unsigned int index;
            unsigned char ch;

            // character we are currently getting count of
            // convert the char to lowercase so we know the count of every letter in string regardless of case
            ch = tolower(inputArray[p][j]);

            if(isalpha(ch)) {
                // Convert character to its alphabet integer position
                index = ch - 'a';

                // increment the count of that character in that sentence
                charCount[p][index]++;
            }

            // count the length of each string, disregarding any punctuation
            if (ch != ' ' && ch != ',' && ch != '!' && ch != '.' && ch != '?')
                lengthString[p]++;
        }
    }

    for (unsigned int x = 0; x < lineNum; x++) {

        for (unsigned int y = x + 1; y < lineNum; y++) {

            if (isAnagram(lengthString, x, y, charCount)) {

                // increment the groups of anagrams
                ++groupsOfAnagrams;

                // call function to output the anagram
                outputAnagram(inputArray, x, y, groupsOfAnagrams);
            }
        }
        free(charCount[x]);
    }

    // free memory
    free(charCount);
}

bool isAnagram(const unsigned int lengthString[], unsigned int x, unsigned int y,
               unsigned int **charCount){

    if (lengthString[x] != lengthString[y]) {
        return false;
    }
    for (unsigned int d = 0; d < 26; d++) {
        if (charCount[x][d] != charCount[y][d]) {
            return false;
        }
    }
    return true;
}
