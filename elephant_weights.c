/*
This program computes the average weight for the set 
of the elephant seals
*/

// including all the needed libraries
#include <stdio.h>

// main() 
int main(void) 
{
    // initializing all the needed variables
    int i;
    int sum = 0;
    int avg = 0;
    int count = 0;
    int numArray[100000];

    // reading a file into an array
    FILE *data_file;
    data_file = fopen("elephant_seal_data.txt", "r");
    
    // counting the number of integers in the file
    while (!feof(data_file)) {
        fscanf(data_file, "%d", &numArray[count]);
        count += 1;
    }
    printf("\ncount: %d\n", count);

    // looping through all the integers in the file
    for (i = 0; i < count - 1; i++) {
        fscanf(data_file, "%d", &numArray[i]);
        printf("Weight is: %d\n", numArray[i]);
        sum += numArray[i]; 
    }
    // computing and printing the average weight
    avg = sum/i;
    printf("\nAvergae weight = %d\n", avg);

    return 0;
}
// end of main()

