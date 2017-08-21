#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
    int x1, x2, x3;
    printf("Please enter three numbers: ");
    scanf("%d %d %d", &x1, &x2, &x3);
    
    (x1 < x2) && (x1 < x3) && (x2 < x3) && printf("%d\n%d\n%d\n", x1, x2, x3);
    (x1 < x2) && (x1 < x3) && (x2 > x3) && printf("%d\n%d\n%d\n", x1, x3, x2);
    (x1 < x2) && (x1 > x3) && printf("%d\n%d\n%d\n", x3, x1, x2);
   
    (x1 > x2) && (x2 < x3) && (x1 < x3) && printf("%d\n%d\n%d\n", x2, x1, x3);
    (x1 > x2) && (x2 < x3) && (x1 > x3) && printf("%d\n%d\n%d\n", x2, x3, x1);
    (x1 > x2) && (x2 > x3) && printf("%d\n%d\n%d\n", x3, x2, x1);

    return EXIT_SUCCESS;
}

