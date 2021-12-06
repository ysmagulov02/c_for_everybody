/*Option 1*/

#include <stdio.h>

typedef enum month { jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec } month; //declayre type
typedef struct date{ month m; int d;} date; //declayre structure

static const char * const month_name[] = {
    "January",  "February", "March",
    "April",    "May",      "June",
    "July",     "August",   "September",
    "October",  "November", "December",
};

void print_month(struct date date) { //simple function for displaying month and day
    switch (date.m) {
      case jan:
      case feb:
      case mar:
      case apr:
      case may:
      case jun:
      case jul:
      case aug:
      case sep:
      case oct:
      case nov:
      case dec:
        printf("%s %d\n", month_name[date.m], date.d);
        break;
      default:
        printf("Out of range!\n");
        break;
    }
}
date next_day(struct date next) { //next month|day 
    int last_day;
    switch (next.m) {
      case jan:
      case mar:
      case may:
      case jul:
      case aug:
      case oct:
      case dec:
        last_day = 31;
        break;
      case apr:
      case jun:
      case sep:
      case nov:
        last_day = 30;
        break;
      case feb:
        last_day = 28;
        break;
      default:
        return next;
    }
    if (next.d++ == last_day) {
        next.d = 1;
        if (next.m++ == dec) {
            next.m = jan;
        }
    }
    return next;
}

int main() {
    struct date date_1 = { feb, 28};
    struct date date_2 = { mar, 14};
    struct date date_3 = { oct, 31};
    struct date date_4 = { dec, 31};

    print_month(date_1);
    print_month(next_day(date_1));
    printf("\n\n");
    print_month(date_2);
    print_month(next_day(date_2));
    printf("\n\n");
    print_month(date_3);
    print_month(next_day(date_3));
    printf("\n\n");
    print_month(date_4);
    print_month(next_day(date_4));

    return 0;
}