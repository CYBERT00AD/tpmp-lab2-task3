
#ifndef TASKS_H
#define TASKS_H

struct PERSON {
    char Name[50];
    char FAC[50];
    char GROUP[20];
    struct {
        int year;
        int month;
        int day;
    } DATE;
};

struct PhoneOwner {
    char surname[30];
    char name[30];
    char patronymic[30];
    char postal_code[10];
    char country[30];
    char region[30];
    char district[30];
    char city[30];
    char street[30];
    char house[10];
    char apartment[10];
    char phone[20];
};

int is_leap(int year);
long count_days(int day, int month, int year);
void print_persons_sorted(struct PERSON vuz[], int n);
void filter_phones(struct PhoneOwner owners[], int n);

#endif
