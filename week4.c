/* 
This program takes an input file consisting of a series of integrs.
making the first integer the size of the array and the rest of the 
inetegrs elements of the array. The program outputs an output file.
*/


// including all the needed libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to print file
void print_file(FILE * fptr) {
    rewind(fptr);
    char c;
    while ((c = getc(fptr)) != EOF) {
        putc(c, stdout);
    }
}

// function to read file
void read_file(FILE *ifp, int intArray[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        fscanf(ifp, "%d", &intArray[i]);
    }
}

// finding an average of given array elements
double average(int intArray[], int size) {
    int i;
    double avg = 0.0;
    for (i = 0; i < size; i++) {
        avg += intArray[i];
    }
    return (avg/size);
}

// finding the max among the given array elemenets
int find_max(int intArray[], int size) {
    int i;
    int the_max = 0;
    for (i = 0; i < size; i++) {
        int temp_max = intArray[i];
        if (temp_max > the_max) {
            the_max = temp_max;
        }
    }
    return the_max;
}

// function to storre the results (elements, avg, max)
void store_result(int numArray[], int size, double avg, int max, FILE *ofp) {
    char line1[] = "File contained following elements: \n";
    char maximum[] = "Max is:\t";
    char average[] = "Average is:\t";

    // for convertion of int values of our input file
    char input_elements[10];

    // writing line 1 to the output file
    for (int i = 0; i < strlen(line1); i++) {
        putc(line1[i], ofp);
    }

    // writing all integers to the output file
    for (int i = 0; i < size; i++) {

        // converting each int to str and writing to the output file
        sprintf(input_elements, "%d", numArray[i]);
        for (int j = 0; j < strlen(input_elements); j++) {
            putc(input_elements[j], ofp);
        }
        putc('\t', ofp);

        // new line every 10 elements
        if ((i+1) % 10 == 0) {
            putc('\n', ofp);
        }


    }
    putc('\n', ofp);
    putc('\n', ofp);


    // writing max line to the output file
    for (int i = 0; i < strlen(maximum); i++) {
        putc(maximum[i], ofp);
    }

    // converting max value to string
    sprintf(input_elements, "%d", max); 

    // writing max value to the output file
    for (int i = 0; i < strlen(input_elements); i++) {
        putc(input_elements[i], ofp);
    }
    putc('\n', ofp);
    putc('\n', ofp);

    
    // writing avg line to the output file
    for (int i = 0; i < strlen(average); i++) {
        putc(average[i], ofp);

    }

    // converting avg value to string
    sprintf(input_elements, "%lf", avg);

    // writing avg value to the output file
    for (int i = 0; i < strlen(input_elements); i++) {
        putc(input_elements[i], ofp);
    }
    putc('\n', ofp);
    putc('\n', ofp);
}

// main function start
int main(int argc, char *argv[]) {
    FILE *ifp, *ofp;
    int max, sz;
    double avg;

    // checking if we have enough arguments
    if (argc != 2) {
        printf("Need executable inputfile\n");
        exit(1);
    }
    
    // opening input and output files
    ifp = fopen(argv[1], "r");
    ofp = fopen("answer-hw3", "w+");

    // printf("my %s input file as read is\n\n", argv[1]);
    // print_file(ifp);
    // printf("\n");

    // checking whether input file has any data
    if (fscanf(ifp, "%d", &sz) != 1) {
        printf("File empty\n");
        exit(1);
    }

    int data[sz];
    read_file(ifp, data, sz);

    // storing values of max and avg
    avg = average(data, sz);
    max = find_max(data, sz);

    store_result(data, sz, avg, max, ofp);
    print_file(ofp);

    // closing files
    fclose(ifp);
    fclose(ofp);

} // main function end