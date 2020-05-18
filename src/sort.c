#include "stdlib.h"
#include <string.h>
#include "extra.h"
#include "sort.h"


void swap(char **array,  int i,  int j){

    // temporary variable
    char *temp = calloc(STRINGLEN, sizeof(char));

    // copy element to temp variable
    memmove(temp, array[i], STRINGLEN);

    //copy array[j] to array[i]
    memmove(array[i], array[j], STRINGLEN);
    // copy the temp var to array[j]
    memmove(array[j], temp, STRINGLEN);

    free(temp);

}

int partition(char **array,  int first,  int last) {

    // swap middle value into the first position
    swap(array, first, (first + last) / 2);

    // we use the first value (which was the middle value) as the pivot
     int pivot = first;

    // index of first unknown value
     int index1 = first + 1;

    // index of last unknown value
     int index2 = last;

    while (index1 <= index2) {
        // use strcasecmp to compare two strings which ignores the case of the characters

        // ensure all elements in index1 array are less than the pivot
        if  (strncasecmp(array[index1],array[pivot], STRINGLEN) < 0) {
            // increment index of element ( because it is less than pivot)
            index1++;
        }

        // ensure all elements in index2 array are greater than the pivot
        else if  (strncasecmp(array[index2],array[pivot], STRINGLEN) > 0)
            // decrement index of element
            index2--;
        else {
            // swap the indexes
            swap(array, index1, index2);
            index1++;
            index2--;
        }
    }
    // put the pivot value between the two sublists and return its index
    swap(array, first, index2);
    return index2;
}

void quicksort(char **array,  int first,  int last){

    //if the size of the array is equal to 0 or 1, the array is sorted by definition
    if(first < last){
        // partition the array into two separate groups , one containing elements less than the pivot
        // and another containing the elements which are greater than the pivot
         int pivotindex = partition(array, first, last);

        // recursively quicksort the first partition
        quicksort(array, first, pivotindex-1);

        // recursively quicksort the second partition
        quicksort(array, pivotindex+1, last);
    }
}
