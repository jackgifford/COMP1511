//Created by Miao Du z5135014 & Jack Gifford z5160408
//Created on 2017-08-11
//Takes three numbers, and arranges them into ascending order


#include <stdio.h>
#include <stdlib.h>

int smallestNumber (int a, int b, int c);
int mediumNumber (int a, int b, int c);
int largestNumber (int a, int b, int c);


int main (int argc, char *argv[]) {
    int a, b, c = -1;
    printf("Enter 3 numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    
    int small = smallestNumber(a,b,c);
    int medium = mediumNumber(a,b,c);
    int large = largestNumber(a,b,c);
    
    printf("%d\n%d\n%d\n", small, medium, large);
    
    return EXIT_SUCCESS;
}
int smallestNumber (int a, int b, int c) {
    if(a <= b && a <= c) {
        return a;
    } else if(b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

int mediumNumber (int a, int b, int c) {
    if((b <= a && a <= c) || (c <= a && a <= b)){
        return a;
    } else if((a <= b && b <= c) || (c <= b && b <= a)){
        return b;
    } else {
        return c;
    }
}

int largestNumber (int a, int b, int c) {
    if(a >= b && a >= c) {
        return a;
    } else if(b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}
