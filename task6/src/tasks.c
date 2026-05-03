#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Name[50];
    char FAC[20];
    char GROUP[10];
    int year, month, day;
} PERSON;

struct PhoneBook {
    char surname[50];
    char number[20];
};

int is_leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

long count_days(int day, int month, int year) {
    int days_in_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long total = 0;
    for (int y = 1970; y < year; y++) total += is_leap(y) ? 366 : 365;
    for (int m = 1; m < month; m++) {
        if (m == 2 && is_leap(year)) total += 29;
        else total += days_in_months[m - 1];
    }
    return total + (day - 1);
}


int compare_students(const void *a, const void *b) {
    PERSON *p1 = (PERSON *)a;
    PERSON *p2 = (PERSON *)b;
    int res = strcmp(p1->FAC, p2->FAC);
    if (res != 0) return res;
    res = strcmp(p1->GROUP, p2->GROUP);
    if (res != 0) return res;
    if (p1->year != p2->year) return p1->year - p2->year;
    if (p1->month != p2->month) return p1->month - p2->month;
    return p1->day - p2->day;
}


void filter_phones(struct PhoneBook *entries, int count) {
    for (int i = 0; i < count; i++) {
        if (strncmp(entries[i].number, "621", 3) == 0) {
            printf("Found: %s, Number: %s\n", entries[i].surname, entries[i].number);
        }
    }
}
