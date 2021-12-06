#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define SIZE 100

typedef struct list {
    int data;
    struct list *next;
} list;

int is_empty(const list *l) {
    return (l == NULL);
}

list* create_list(int d) {
    list *head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

list* add_to_front(int d, list *h) {
    list *head = create_list(d);
    head -> next = h;
    return head;
}

list* array_to_list(int d[], int size) {
    list* head = create_list(d[0]);
    int i;
    for (i = 1; i < size; i++) {
        head = add_to_front(d[i], head);
    }
    return head;
}

void print_list(list *h, char *title) {
    printf("%s\n", title);
    while (h != NULL) {
        for (int i = 100; i >= SIZE; i--) {
            if ((h->data) < 10) {
                printf("%2d ", h -> data);
                h = h -> next;
            } else {
                printf("%d ", h -> data);
                h = h -> next;
            }
            if ((h->data) < 10) {
                printf("%2d ", h -> data);
                h = h -> next;
            } else {
                printf("%d ", h -> data);
                h = h -> next;
            }
            if ((h->data) < 10) {
                printf("%2d ", h -> data);
                h = h -> next;
            } else {
                printf("%d ", h -> data);
                h = h -> next;
            }
            if ((h->data) < 10) {
                printf("%2d ", h -> data);
                h = h -> next;
            } else {
                printf("%d ", h -> data);
                h = h -> next;
            }
            if ((h->data) < 10) {
                printf("%2d ", h -> data);
                h = h -> next;
            } else {
                printf("%d ", h -> data);
                h = h -> next;
            } 
            printf("\n");
        }
    }
}


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

int main() {
    // random number generator
    srand(time(NULL));
    //srand(1337); 
    
    // creating an array of 100 randomly generated integers
    int rand_numArray[SIZE];
    for (int i = 0; i < SIZE; i++) {
        int r = rand() % 100; // random int btw 0 and 99
        rand_numArray[i] = r;
        //printf("%d ", rand_numArray[i]);
    }

    // bubble sort
    bubbleSort(rand_numArray, SIZE);
    printf("\nSorted array: \n");
    printArray(rand_numArray, SIZE);
    printf("\n");

    // sorted list
    list list_of_int;
    list* head = NULL;
    head = array_to_list(rand_numArray, SIZE);
    print_list(head, "multi element sorted list");
    printf("\n\n");


    return 0;
}