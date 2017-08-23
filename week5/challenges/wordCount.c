//Created by Jack Gifford (z5160408)
//Created on 2017-08-21
//Counts how many words are inputted using getchar.

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

//Function Prototypes
int IsLegalCharacter(char val);

int main (int argc, char *argv[]) {
    char c;
    short wordCount = 0;
    char arr[2] = {0};

    //Initial Vals
    arr[0] = getchar();
    arr[1] = getchar();

    while ((c = getchar()) != EOF) {
        //Checks if the two values in the array are a valid character, and whitespace respectively.
        if (IsLegalCharacter(arr[0]) && !IsLegalCharacter(arr[1])) {
            wordCount++;
        } 

        arr[0] = arr[1];
        arr[1] = c;
    }

    printf("%d words\n", wordCount);
    
    return EXIT_SUCCESS;
}

int IsLegalCharacter(char val) {
    if (val >= 'a' && val <= 'z') {
        return TRUE;
    } else if (val >= 'A' && val <= 'Z') {
        return TRUE;
    } else if (val == '-' || val == '_' || val == '\'') {
        return TRUE;
    } else if (val >= '0' && val <= '9') {
        return TRUE;
    }

    return FALSE;
}
