//Created by Jack Gifford (z5160408)
//Returns the sum of the values inputted using a loop
//Created on 2017-08-20

#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
    printf("How many numbers: ");
    int numberCount = -1;
    scanf("%d", &numberCount);
    if (numberCount < 0) {
        printf("Invalid number count, enter a value greater than or equal to zero\n");

        return EXIT_FAILURE;
    }
    
    int valuesLeft = numberCount;
    int sum = 0;
    int currentNum;
    
    while (valuesLeft > 0) {
        scanf("%d", &currentNum);
        sum += currentNum;
        valuesLeft--;
    }
    printf("%d\n", sum);
    
    return EXIT_SUCCESS;

}
