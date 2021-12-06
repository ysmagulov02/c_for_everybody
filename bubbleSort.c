#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// bubble sort functions
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        // last i elements are already in place
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
 

#define SIZE 100
int main()
{

    srand(time(NULL)); 
    
    // creating an array of 100 randomly generated integers
    int rand_numArray[SIZE];
    for (int i = 0; i < SIZE; i++) {
        int r = rand() % 100; // random int btw 0 and 99
        rand_numArray[i] = r;
        //printf("%d ", rand_numArray[i]);
    }





    // int arr[] = {64, 34, 25, 12, 22, 11, 90};
    // int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(rand_numArray, SIZE);
    printf("Sorted array: \n");
    printArray(rand_numArray, SIZE);
    return 0;
}