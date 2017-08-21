// Created by Jack Gifford z5160408
// Prints out two numbers provided by the user and returns the sum, if any value is between -10, and 10
// It returns the word version of the number.
// Created on 2017-08-4


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num1 = -1;
    int num2 = -1;

    printf("Please enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    int sum = num1 + num2;
    int absNum1 = num1;
    int absNum2 = num2;
    int absSum = sum;

    if (num1 < 0) {
        absNum1 = -1 * num1;
    }

    if (num2 < 0) {
        absNum2 = -1 * num2;
    }

    if (sum < 0) {
        absSum = -1 * sum;
    }
    

    if (num1 < 0) {
        printf("negative ");
    }

    if (absNum1 == 0) {
        printf("zero");
    }

    else if (absNum1 == 1) {
        printf("one");
    }

    else if (absNum1 == 2) {
        printf("two");
    }

    else if (absNum1 == 3) {
        printf("three");
    }

    else if (absNum1 == 4) {
        printf("four");
    }

    else if (absNum1 == 5) {
        printf("five");
    }

    else if (absNum1 == 6) {
        printf("six");
    }

    else if (absNum1 == 7) {
        printf("seven");
    }

    else if (absNum1 == 8) {
        printf("eight");
    }

    else if (absNum1 == 9) {
        printf("nine");
    } 
    
    else if (absNum1 == 10) {
        printf("ten");
    }

    else {
        printf("%d", num1);
    }

    printf(" + ");

    if (num2 < 0) {
        printf("negative ");
    }

    if (absNum2 == 0) {
        printf("zero");
    }

    else if (absNum2 == 1) {
        printf("one");
    }

    else if (absNum2 == 2) {
        printf("two");
    }

    else if (absNum2 == 3) {
        printf("three");
    }

    else if (absNum2 == 4) {
        printf("four");
    }

    else if (absNum2 == 5) {
        printf("five");
    }

    else if (absNum2 == 6) {
        printf("six");
    }

    else if (absNum2 == 7) {
        printf("seven");
    }

    else if (absNum2 == 8) {
        printf("eight");
    }

    else if (absNum2 == 9) {
        printf("nine");
    } 
    
    else if (absNum2 == 10) {
        printf("ten");
    }

    else {
        printf("%d", num2);
    }

    printf(" = ");

    if (absSum < 0) {
        printf("negative ");
    }

    if (absSum == 0) {
        printf("zero\n");
    }

    else if (absSum == 1) {
        printf("one\n");
    }

    else if (absSum == 2) {
        printf("two\n");
    }

    else if (absSum == 3) {
        printf("three\n");
    }

    else if (absSum == 4) {
        printf("four\n");
    }

    else if (absSum == 5) {
        printf("five\n");
    }

    else if (absSum == 6) {
        printf("six\n");
    }

    else if (absSum == 7) {
        printf("seven\n");
    }

    else if (absSum == 8) {
        printf("eight\n");
    }

    else if (absSum == 9) {
        printf("nine\n");
    } 
    
    else if (absSum == 10) {
        printf("ten\n");
    }

    else {
        printf("%d\n", sum);
    }

    return EXIT_SUCCESS;
}
