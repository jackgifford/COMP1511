//Created by Jack Gifford (z5160408) & Miao Du (z5135014)
//Created on 2017-08-18
//Prints out a danish flag in ASCII Art

#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
    int size = -1;
    printf("Enter the flag size: ");
    scanf("%d", &size);
    
    int blockWidth = size * 3;
    int blockHeight = size * 2;
    
    int height = size*4;
    int width = blockWidth * 3;
    
    //Rows and columns that are whitespace
    int rightColumn = blockWidth -1;
    int leftColumn = blockWidth;
    int bottomRow = blockHeight -1;
    int topRow = blockHeight;
    
    int rowCount = 0;
    int colCount = 0;
    
    while (rowCount < height) {
        while (colCount < width) {
            if (rowCount == bottomRow || rowCount == topRow || colCount == leftColumn || colCount == rightColumn) {
                printf(" ");
            } else {
                printf("#");
            }
            colCount++;
        }
        printf("\n");
        rowCount++;
        colCount = 0;
    }
    
    return EXIT_SUCCESS;
}
