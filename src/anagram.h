#ifndef SEPROJECT_ANAGRAM_H
#define SEPROJECT_ANAGRAM_H

#include <stdbool.h>

void findAnagrams(char **inputArray, int lineNum);
bool isAnagram(const unsigned int lengthString[], unsigned int x, unsigned int y,
               unsigned int **charCount);

#endif //SEPROJECT_ANAGRAM_H
