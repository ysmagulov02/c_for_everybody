#include <stdio.h>

#define MAX 20

void read_data(FILE *ptr, int intArray[], int *size) {
    *size = 0;
    while(fscanf(ptr, "%d", &intArray[*size]) == 1) {
        (*size)++;
    }
}

void print_data(int intArray[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d\t", intArray[i]);
        if ((i+1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

double average(int intArray[], int size) {
    int i;
    double avg = 0.0;
    for (i = 0; i < size; i++) {
        avg += intArray[i];
    }
    return (avg/size);
}

int max(int intArray[], int size) {
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

int main() {
    int i, sz = MAX;
    FILE *ifp;
    int data[MAX];

    ifp = fopen("integers", "r");
    read_data(ifp, data, &sz);
    printf("\nmy %d integers are:", sz);
    print_data(data, sz);
    printf("\n average is %f ", average(data, sz));
    printf("\n");
    printf("\n max is %d", max(data, sz));
    printf("\n\n");
    fclose(ifp);
    return 0;
}