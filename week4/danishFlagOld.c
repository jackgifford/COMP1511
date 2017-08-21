#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

void RenderBlocks (int whiteSpaceRow, int block1WhitespaceColumn, int block2WhitespaceColumn, int blockWidth, int blockHeight) {
    int flagWidth = blockWidth * 3;
    
    int currentRow = 0;
    int currentColumn = 0;
    int isPixelWhiteSpace = TRUE;
    while (currentRow < blockHeight) {
        while (currentColumn < flagWidth) {
            if (currentRow != whiteSpaceRow) {
                if (currentColumn < blockWidth) {
                    if (currentColumn != block1WhitespaceColumn) {
                        isPixelWhiteSpace = FALSE;
                    }
                } else if (currentColumn <  2 * blockWidth) {
                    if (currentColumn != block2WhitespaceColumn) {
                        isPixelWhiteSpace = FALSE;
                    }
                } else {
                    isPixelWhiteSpace = FALSE;
                }
            }
            
            if (isPixelWhiteSpace == TRUE) {
                printf(" ");
            } else {
                printf("#");
            }
            isPixelWhiteSpace = TRUE;
            currentColumn++;
        }
        printf("\n");
        currentColumn = 0;
        currentRow++;
    }
}

int main (int argc, char *argv[]) {
    int size = -1;
    printf("Enter the flag size: ");
    scanf("%d", &size);
    
    int blockWidth = size * 3;
    int blockHeight = size * 2;
    
    //Rows and columns that are whitespace
    int rightColumn = blockWidth -1;
    int leftColumn = blockWidth;
    int bottomRow = blockHeight -1;
    int topRow = 0;
    
    RenderBlocks(bottomRow, rightColumn, leftColumn, blockWidth, blockHeight);
    RenderBlocks(topRow, rightColumn, leftColumn, blockWidth, blockHeight);
    
    return EXIT_SUCCESS;
}
