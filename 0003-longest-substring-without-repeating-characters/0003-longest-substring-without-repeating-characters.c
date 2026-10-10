#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



bool checkIfInList(char letter, char* list, int listSize, int initialValue, int* matchIndex) {
    
    for (int i = initialValue; i < listSize; i++) {

        if (letter == list[i]){
            *matchIndex = i;
            return true;
        }
    }

    /* If not in list, then add*/

    list[listSize] = letter;

    return false;
}



int lengthOfLongestSubstring(char* s) {
    int length = strlen(s);
    char* list = (char*) malloc(length);

    int listSize = 0;
    int startFromValue = 0;

    int currentValue = 0;
    int largestValue = 0;

    for (int a = 0; a < length; a++) {

        int matchIndex = -1;

        if (checkIfInList(s[a], list, listSize, startFromValue, &matchIndex)) {
                startFromValue = matchIndex + 1;
                currentValue = 0;
                list[listSize] = s[a];

        
        }
        
        listSize++;
        int currentWindow = listSize - startFromValue;
        if (currentWindow > largestValue) {
            largestValue = currentWindow;

        }
    
    }
    return largestValue;
}
