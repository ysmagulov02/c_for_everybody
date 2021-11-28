/*
This program prints out a table of the sine and cos values 
between 0 and 1 (non inclusive)
*/

// including all the needed libraries
#include <stdio.h>
#include <math.h>

// main() 
int main(void) 
{
    double x, sin_val, cos_val;
    float i;

    // starting at 0.0, loop until loop index reaches 1, increment loop index by 0.1 after each iteration
    for (i=0.0; i<=1.1; i+=0.1) {
        sin_val = sin(i);
        cos_val = cos(i);
        printf("\nThe sin value of %lf is %lf ", i, sin_val);
        printf("\nThe cos value of %lf is %lf \n", i, cos_val);
    }
    printf("\n");
    return 0;
}
// end of main()
