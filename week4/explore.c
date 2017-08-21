//  Exploring memory
//  Created by Richard Buckland on 2012-11-20.
//
//  Modified by:
//      Jack Gifford (z5160408)
//      Miao Du (z5135014)
//
//  2017-08-18

#include <stdio.h>
#include <stdlib.h>

long add (int x, int y);

int main(int argc, const char * argv[]) {

    int x;
    double y;
    long total;

    x = 40;
    y = 40.0;

    printf("Overflow Example\n");
    unsigned char maxChar = 255;
    maxChar += 10;
    
    printf("Overflow: 255 + 10 = %d\n",maxChar); 
    
    printf("Underflow Example\n");
    
   
    unsigned char minChar = 0;
    minChar -= 10;
    printf("\n");
    printf("Underflow Example\n");
    printf("Underflow: 0 - 10 = %d\n",minChar); 
    printf("\n");
    

    printf("The size of a int, in bytes, is %lu.\n", sizeof(x));
    printf("The size of a double, in bytes, is %lu.\n", sizeof(y));
    total = add (x, y);

    printf("the sum of %d and %d is %ld\n", x, y, total);

    char c ='a';

    unsigned long ul       = 0;
    unsigned int ui        = 1;
    unsigned long long ull = 2;
    unsigned short us      = 3;
    unsigned char uc = 1;

    signed long sl       = 4;
    signed int si        = 5;
    signed long long sll = 6;
    signed short ss      = 7;
    signed char sc = 1;

    long l       = 8;
    int i        = 9;
    long long ll = 10;
    short s      = 11;

    float f = 3.1;
    double d = 3.14;
    char e = 1;
    printf("The location of f is %p\n", &f);
    printf("The location of d is %p\n", &d);
    printf("The location of e is %p\n", &e);
    printf("\n");
    printf("The location of x is %p\n", &x);
    printf("The location of y is %p\n", &y);
    printf("The location of total is %p\n", &total);
    printf("\n");
    printf("---Unsigned variable locations---\n");
    printf("The location of ul is %p\n", &ul);
    printf("The location of ui is %p\n", &ui);
    printf("The location of ull is %p\n", &ull);
    printf("The location of us is %p\n", &us);
    printf("The location of uc is %p\n", &uc);
    printf("\n");
    printf("---Signed variable locations---\n");
    printf("The location of sl is %p\n", &sl);
    printf("The location of si is %p\n", &si);
    printf("The location of sll is %p\n", &sll);
    printf("The location of ss is %p\n", &ss);
    printf("The location of sc is %p\n", &sc);
    printf("\n");
    
    printf("--- Unsigned variable lengths --- \n");
    printf("The size of an unsigned long in bytes is %lu.\n", sizeof(ul));
    printf("The size of an unsigned int in bytes is %lu.\n", sizeof(ui));
    printf("The size of an unsigned long long in bytes is %lu.\n", sizeof(ull));
    printf("The size of an unsigned short in bytes is %lu.\n", sizeof(us));
    printf("The size of an unsigned char in bytes is %lu.\n", sizeof(sc));
    
    printf("\n");
    
    printf("--- Signed variable lengths --- \n");
    printf("The size of a signed long in bytes is %lu.\n", sizeof(sl));
    printf("The size of a signed int in bytes is %lu.\n", sizeof(si));
    printf("The size of a signed long long in bytes is %lu.\n", sizeof(sll));
    printf("The size of a signed short in bytes is %lu.\n", sizeof(ss));
    printf("The size of a signed char in bytes is %lu.\n", sizeof(sc));
    
    printf("\n");
    
    printf("--- Plain variable lengths --- \n");
    printf("The size of a long in bytes is %lu.\n", sizeof(l));
    printf("The size of a int in bytes is %lu.\n", sizeof(i));
    printf("The size of a long long in bytes is %lu.\n", sizeof(ll));
    printf("The size of a short in bytes is %lu.\n", sizeof(s));
    printf("The size of a char in bytes is %lu.\n", sizeof(e));
    printf("The size of a double in bytes is %lu.\n", sizeof(d));
    printf("The size of a float in bytes is %lu.\n", sizeof(f));
    
    printf("\n");
    
    

    // add them all together just to make use of them so the compiler
    // doesn't grumble that they are unused in the program

    double grandTotal;
    grandTotal =  c +
        ul + ui + ull + us +
        sl + si + sll + ss +
        l +  i +  ll +  s +
        f + d;

    printf ("all these things added together make %f\n",
            grandTotal);

    // Add in your own variables, printf statements and arithmetic to
    // figure out the size of different types, where they live
    // and how big the numebrs they store are

    return EXIT_SUCCESS;
}

long add (int x, int y) {
    long answer;
    answer = x + y;

    return answer;
}

