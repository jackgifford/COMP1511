#include <stdio.h>
#include <stdlib.h>

int IsLegalCharacter(char val) {
    if (val >= 'a' && val <= 'z') {
        return 1;
    } else if (val >= 'A' && val <= 'Z') {
        return 1;
    } else if (val == '-' || val == '_') {
        return 1;
    } else if (val >= '0' && val <= '9') {
        return 1;
    }

    return 0;
}

int main (int argc, char *argv[]) {

    char c;
    short wordCount = 0;
    int i;
    char arr[2] = {0};

    //Initial Vals
    arr[0] = getchar();
    arr[1] = getchar();

    while ((c = getchar()) != EOF) {
        if (IsLegalCharacter(arr[0]) && !IsLegalCharacter(arr[1])) {
            wordCount++;
        } 

        arr[0] = arr[1];
        arr[1] = c;
    }

    printf("%d words\n", wordCount);
    
    return EXIT_SUCCESS;
}