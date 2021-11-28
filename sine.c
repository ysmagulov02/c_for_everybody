/*
This program gives the sine of a value 
between 0 and 1 (non inclusive)
*/

// including all the needed libraries
#include <stdio.h>
#include <math.h>

// main() 
int main(void) 
{
    double x, sin_val;
    printf("Enter x value between 0 and 1: ");
    scanf("%lf", &x);
    // if input is out of bounds, print an error and exit the program
    if (x < 0 || x > 1) {
        printf("Invalid input\n");
        return 0;
    }
    sin_val = sin(x);
    printf("The sine value of %lf is %lf ", x, sin_val);
    
    return 0;
}
// end of main()
