#ifndef TASKS_H
#define TASKS_H

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

int is_leap(int y);
long count_days(int day, int month, int year);
int compare_students(const void *a, const void *b);
void filter_phones(struct PhoneBook *entries, int count);

#endif
