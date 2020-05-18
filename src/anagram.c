#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "anagram.h"
#include "outputResults.h"

#define LETTERSINALPHABET 26

void checkAnagram(char **inputArray, int lineNum) {

    unsigned int lengthString[lineNum], groupsOfAnagrams = 0, index;
    int **charCount = calloc(lineNum , sizeof(charCount));
    char **anagrams = calloc(lineNum , sizeof(anagrams));
    unsigned char ch;

    for (unsigned int p = 0; p < lineNum; p++) {
        lengthString[p] = 0;
        charCount[p] = calloc(LETTERSINALPHABET , sizeof(int));

        for (unsigned int j = 0; inputArray[p][j] != '\0'; j++) {

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

            bool anagram = true;

            if (lengthString[x] != lengthString[y]) {
                continue;
            }
            for (unsigned int d = 0; d < 26; d++) {

                if (charCount[x][d] != charCount[y][d]) {
                    anagram = false;
                    break;
                }
            }

            if (anagram) {

                // increment the groups of anagrams
                ++groupsOfAnagrams;

                // call function to output the anagram
                outputAnagrams(inputArray, x, y, groupsOfAnagrams);
            }
        }
        free(charCount[x]);
    }

    // free memory
    free(charCount);

    free(anagrams);
}

