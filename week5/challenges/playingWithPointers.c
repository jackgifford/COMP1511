#include <stdio.h>
#include <stdlib.h>

void manipulate(int *x) {
    printf("%p\n", x);
    *x = *x + 4;
}

void swap(int *x, int *y) {
    int temp;
    printf("%p\n", x);
    temp = *x;
    *x = *y;
    *y = temp;

}

int * findMax(int a[], int n) {
    int i, currentMaxPos = 0;
    for (i = 0; i < n; i++) {
        if (a[i] > currentMaxPos) {
            currentMaxPos = i;
        }
    }
    
    
    return &a[currentMaxPos];
}

void findTwoLargestVals(int a[], int n, int *largest, int *secondLargest) {
    int i; 

    for (i = 0; i < n; i++) {
        if (a[i] > *largest) {
            *secondLargest = *largest;
            *largest = a[i];
        }
    }

}

int main (int argc, char *argv[]) {

    int length = 10;
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int max = 0, secondMax = 0;

    int *p = findMax(arr, length);
    printf("The address of the largest val is %p, and its value is %d\n", p, *p);

    findTwoLargestVals(arr, length, &max, &secondMax);
    printf("The largest val is %d and the second largest is %d\n", max, secondMax);
    
}