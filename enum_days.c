/* 
This program prints out the date (month and day) 
and the following date (month and day)
*/

// including all the needed libraries
#include <stdio.h>

// declaring type
typedef enum month{ jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} month;
struct date{ month m; int d;} date;

// printing the date
void printdate(struct date date) {
    switch(date.m) {
        case jan: printf("January %d", date.d); break;
        case feb: printf("February %d", date.d); break;
        case mar: printf("March %d", date.d); break;
        case apr: printf("April %d", date.d); break;
        case may: printf("May %d", date.d); break;
        case jun: printf("June %d", date.d); break;
        case jul: printf("July %d", date.d); break;
        case aug: printf("August %d", date.d); break;
        case sep: printf("September %d", date.d); break;
        case oct: printf("October %d", date.d); break;
        case nov: printf("November %d", date.d); break;
        case dec: printf("December %d", date.d); break;
    }
}

// function for next day
struct date next_day(struct date date) {
    switch(date.m) {
        case jan:
            if (date.d >= 31) {
                date.d = 1;
                date.m = feb;
            } else {
                date.d++; 
            }
            break;
        case feb:
            if (date.d >= 28) {
                date.d = 1;
                date.m = mar;
            } else {
                date.d++;
            }
            break;
        case mar:
            if (date.d >= 31) {
                date.d = 1;
                date.m = apr;
            } else {
                date.d++;
            }
            break;
        case apr:
            if (date.d >= 30) {
                date.d = 1;
                date.m = may;
            } else {
                date.d++;
            }
            break;
        case may:
            if (date.d >= 31) {
                date.d = 1;
                date.m = jun;
            } else {
                date.d++;
            }
            break;
        case jun:
            if (date.d >= 30) {
                date.d = 1;
                date.m = jul;
            } else {
               date.d++; 
            }
            break;
        case jul:
            if (date.d >= 31) {
                date.d = 1;
                date.m = aug;
            } else {
               date.d++; 
            }
            break;
        case aug:
            if (date.d >= 31) {
                date.d = 1;
                date.m = sep;
            } else {
               date.d++; 
            }
            break;
        case sep:
            if (date.d >= 30) {
                date.d = 1;
                date.m = oct;
            } else {
               date.d++; 
            }
            break;
        case oct:
            if (date.d >= 31) {
                date.d = 1;
                date.m = nov;
            } else {
               date.d++; 
            }
            break;
        case nov:
            if (date.d >= 30) {
                date.d = 1;
                date.m = dec;
            } else {
                date.d++;
            }
            break;
        case dec:
            if (date.d >= 31) {
                date.d = 1;
                date.m = jan;
            } else {
                date.d++;
            }
            break;  
        default: printf("%d is an error", date.m);
    }

    return date;
}

// main()
/* 
here I was testing different dates to make sure 
everything works as expected
*/
int main() {
    struct date today;

    today.m = jan;
    today.d = 1;
    printf("\n");
    printdate(today);
    printf("\n");
    printdate(next_day(today));
    printf("\n");

    today.m = feb;
    today.d = 28;
    printf("\n");
    printdate(today);
    printf("\n");
    printdate(next_day(today));
    printf("\n");

    today.m = mar;
    today.d = 14;
    printf("\n");
    printdate(today);
    printf("\n");
    printdate(next_day(today));
    printf("\n");

    today.m = oct;
    today.d = 31;
    printf("\n");
    printdate(today);
    printf("\n");
    printdate(next_day(today));
    printf("\n");

    today.m = dec;
    today.d = 31;
    printf("\n");
    printdate(today);
    printf("\n");
    printdate(next_day(today));
    printf("\n\n");

    // end of the program
    return 0;
}