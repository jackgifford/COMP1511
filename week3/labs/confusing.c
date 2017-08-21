//Created by Julian Saknussemm, and modified by Jack Gifford (z5160408) and Miao Du (z5135014)
//Modified on 2017-08-11
//Modified Julian's code so that it is easier to understand

/*
* Test if a point is inside a triangle.
* Julian Saknussemm
*
* Given Three points of a triangle, and another arbitrary point this program
* determines if that point lies inside
* the triangle.
*
* This is determined by satisfying the following rule:
* A point P(x,y) is inside triangle A(x0,y0), B(x1,y1), C(x2,y2)
* iff
* P is on the same side of the line AB as C
* P is on the same side of the line BC as A
* and
* P is on the same side of the line AC as B
*
* A special case exits for a vertical line (inf gradient) when testing the side
*  of the line
*/


#include <stdio.h>
#include <stdlib.h>

#define UNDER_LINE -1
#define ON_LINE 0
#define OVER_LINE 1


//Prototypes
int CheckPointsOnSameSide(double px, double py, double m,double b, double lx,double ly);
int CheckPointInTriangle(double x0, double y0, double x1, double y1, double x2, double y2, double px, double py);
int CheckPointLocation(double px, double py, double m, double b);

int main(int argc, char *argv[]) {
    double x0, y0, x1, y1, x2, y2, px, py = -1;

    //Check to make sure user has entered the correct amount of inputs
    int scanfsTotalInputs= 0;

    //Get input
    printf("Triangle Vertex A (x,y): ");
    scanfsTotalInputs += scanf("%lf,%lf", &x0,&y0);
    printf("Triangle Vertex  B (x,y): ");
    scanfsTotalInputs += scanf("%lf,%lf", &x1,&y1);
    printf("Triangle Vertex  C (x,y): ");
    scanfsTotalInputs += scanf("%lf,%lf", &x2,&y2);
    printf("Test Point (x,y): ");
    scanfsTotalInputs += scanf("%lf,%lf", &px,&py);

    //Print error
    if(scanfsTotalInputs != 8) {
        printf("Please enter the correct amount of inputs.\n");
        return EXIT_FAILURE;
    }
    //Prevents division by zero when calculating slopes
    if ((x1-x0 == 0) || (x2-x0 == 0) || (x2 -x1 == 0)) {
        printf("The line between two of the points you entered will create a gradient of infinity, and crash the program!\n");
        printf("Please enter three points that won't create any slopes that are equal to infinity");
        return EXIT_FAILURE;
    }

    //Print answer
    printf("Point (%.2lf,%.2lf) is ", px,py);
    if(CheckPointInTriangle(x0,y0,x1,y1,x2,y2,px,py)) {
        printf("inside");
    } else {
        printf("outside");
    }
    printf(" the triangle\n");
    
    return EXIT_SUCCESS;
}

int CheckPointLocation(double px, double py, double m, double b)
{
    if(py < m * px + b) {
        return UNDER_LINE;//Point is under the line
    } else if (py == m * px + b){
        return ON_LINE;//Point is on the line
    } else {
        return OVER_LINE;//Point is over the line
    }
}

//Two points lie on the same side of a line
int CheckPointsOnSameSide(double px, double py, double m,double b, double lx,double ly) {
    return (CheckPointLocation(px, py, m, b) == CheckPointLocation(lx, ly, m, b));
}

int CheckPointInTriangle(double x0, double y0, double x1, double y1, double x2, double y2, double px, double py){
    //Line eqns
    int line1, line2, line3;
    
    //Calculate slope of lines
    double line1Slope = (y1-y0)/(x1-x0);
    double line2Slope = (y2-y0)/(x2-x0);
    double line3Slope = (y2-y1)/(x2-x1);
    //yIntercept: y - y1 = slope(x - x1), x = 0, as this is where the y intercept occurs
    //Calculate the y intercept for lines
    double line1YIntercept = line1Slope * -x1 + y1;
    double line2YIntercept = line2Slope * -x2 + y2;
    double line3YIntercept = line3Slope * -x2 + y2;

    //Vertical line checks
    if(x1 == x0) {
        line1 = ((px <= x0) == (x2 <= x0));
    } else {
        line1 = CheckPointsOnSameSide(px, py, line1Slope, line1YIntercept, x2, y2);
    }

    if(x1 == x2) {
        line2 = ((px <= x2) == (x0 <= x2));
    } else {
        line2 = CheckPointsOnSameSide(px, py, line3Slope, line3YIntercept, x0, y0);
    }
    if(x2 == x0) {
        line3 = ((px <= x0) == (x1 <= x0));
    } else {
        line3 = CheckPointsOnSameSide(px, py, line2Slope, line3YIntercept, x1, y1);
    }
    return line1 && line2 && line3;
}

