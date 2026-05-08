
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tasks.h"

int is_leap(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

static int days_in_month(int month, int year) {
    static const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2 && is_leap(year))
        return 29;
    return days[month-1];
}

long count_days(int day, int month, int year) {
    long total = 0;
    for (int y = 1970; y < year; y++)
        total += is_leap(y) ? 366 : 365;
    for (int m = 1; m < month; m++)
        total += days_in_month(m, year);
    total += day - 1;
    return total;
}

static int date_compare(const struct PERSON *a, const struct PERSON *b) {
    if (a->DATE.year != b->DATE.year)
        return a->DATE.year - b->DATE.year;
    if (a->DATE.month != b->DATE.month)
        return a->DATE.month - b->DATE.month;
    return a->DATE.day - b->DATE.day;
}

static int cmp_for_output(const void *p1, const void *p2) {
    const struct PERSON *a = p1, *b = p2;
    int fac_cmp = strcmp(a->FAC, b->FAC);
    if (fac_cmp != 0) return fac_cmp;
    int grp_cmp = strcmp(a->GROUP, b->GROUP);
    if (grp_cmp != 0) return grp_cmp;
    int date_cmp = date_compare(a, b);
    if (date_cmp != 0) return date_cmp;
    return strcmp(a->Name, b->Name);
}

void print_persons_sorted(struct PERSON vuz[], int n) {
    struct PERSON *copy = malloc(n * sizeof(struct PERSON));
    if (!copy) return;
    memcpy(copy, vuz, n * sizeof(struct PERSON));
    qsort(copy, n, sizeof(struct PERSON), cmp_for_output);
    for (int i = 0; i < n; i++) {
        printf("%s, %s, %s, %04d-%02d-%02d\n",
               copy[i].Name, copy[i].FAC, copy[i].GROUP,
               copy[i].DATE.year, copy[i].DATE.month, copy[i].DATE.day);
    }
    free(copy);
}

void filter_phones(struct PhoneOwner owners[], int n) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strncmp(owners[i].phone, "621", 3) == 0) {
            printf("%s %s %s, тел: %s\n",
                   owners[i].surname, owners[i].name, owners[i].patronymic,
                   owners[i].phone);
            found = 1;
        }
    }
    if (!found)
        printf("Нет таких владельцев.\n");
}
