// favourite number 3
// calculates and displays some information about a user entered integer
// 2017-08-10   Alex Linker <{a.linker, z5061930}@unsw.edu.au>
//              Jashank Jeremy <{jashankj, z5017851}@cse.unsw.edu.au>

//Modifed by Tiffany (Miao Du z5135014)  and Jack Gifford (z5160408)
//2017-08-18


#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

#define LAST_TIMES_TABLE 12

// Function prototypes
void printTimesTable (int n);
int factorial (int n);
int isPerfectNumber (int n);

int main (int argc, char *argv[]) {
    // !!! DO NOT CHANGE THIS MAIN FUNCTION !!! \\

    // Gets a user entered number.
    printf ("Enter your favourite number: ");

    // Check to see if a valid integer was entered.
    int num;
    if (scanf ("%d", &num) != 1) {
        printf ("Couldn't read an integer.\n");
        return EXIT_FAILURE;
    }

    // Check to see if the integer was positive.
    if (num < 0) {
        printf ("You didn't enter a positive number.\n");
        return EXIT_SUCCESS;
    }

    // Print out some facts.
    printf ("You entered %d.\n", num);

    // Print their number's factorial.
    int fact = factorial (num);
    printf ("%d! = %d\n", num, fact);

    // Print the times table.
    printTimesTable (num);

    // Print whether the number is a perfect number.
    if (isPerfectNumber (num) == TRUE) {
        printf ("%d is a perfect number.\n", num);
    } else {
        printf ("%d is not a perfect number.\n", num);
    }

    return EXIT_SUCCESS;
}

// END OF MAIN FUNCTION

// Print the 1-12 times tables of the inputted number.
void printTimesTable (int n) {
    int i = 1;
    while(i <= 12) {
        int sum = i * n;
        printf("%d x %d = %d\n", i, n, sum);
        i++;
    }
}

// Return the factorial of n.
int factorial (int n) {
    int i = 2;
    int factorial = 1;
    while (i <=  n) {
        factorial = factorial * i;
        i++;
    }

    return factorial; // change this line to your return value
}

// Return TRUE if n is a perfect number, FALSE otherwise.
int isPerfectNumber (int n) {
    // PUT YOUR CODE HERE
    int isPerfectNumber = FALSE;
    int i = 1;
    int sumOfFactors = 0;
    while (i < n) {
        if (n % i == 0) {
            sumOfFactors += i;
        }
        i++;
    }
    
    if (sumOfFactors == n) {
        isPerfectNumber = TRUE;
    }
    
    return isPerfectNumber; // change this line to your return value
}

