#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
  	// Complete the code to print the pattern.

    int len = 2*n - 1;
    int temp_i, temp_j;
    int val;

    //int len = 9;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (j+1 > n){
                temp_j = abs(n - j+1);
            } else if (j+1 == n) {
                temp_j = abs(n - j);
            } else {
                temp_j = j;
            }

            if (i+1 > n){
                temp_i = abs(n - i+1);
            } else if (i+1 == n) {
                temp_i = abs(n - i);
            } else {
                temp_i = i;
            }


            val = n - temp_j*temp_i;
            printf("%d ",val);
        }
        printf("\n");
    }

    // for (int i = length; i > 0; i--) { // row
    //     for (int j = length; j > 0; j--) { // column
            
    //     }
    // }
      
      
    return 0;
}