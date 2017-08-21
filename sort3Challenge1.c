//Written by Jack Gifford z5160408
//Written on 2017-08-13
//Given three numbers it will print them into ascending order

#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
    int x1, x2, x3;
    printf("Enter 3 numbers: ");
    scanf("%d %d %d", &x1, &x2, &x3);
    
    
    (x1 < x2) & (x1 < x3) & (x2 < x3) && printf("%d\n%d\n%d\n", x1, x2, x3);
    (x1 < x2) & (x1 < x3) & (x2 >= x3) && printf("%d\n%d\n%d\n", x1, x3, x2);
    (x1 < x2) & (x1 >= x3) & printf("%d\n%d\n%d\n", x3, x1, x2);
    
    (x1 >= x2) & (x2 < x3) & (x1 < x3) && printf("%d\n%d\n%d\n", x2, x1, x3);
    (x1 >= x2) & (x2 < x3) & (x1 >= x3) && printf("%d\n%d\n%d\n", x2, x3, x1);
    (x1 >= x2) & (x2 >= x3) & printf("%d\n%d\n%d\n", x3, x2, x1);

    return EXIT_SUCCESS;
}
