#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tasks.h"

void test_is_leap() {
    printf("Тестирование is_leap()\n");
    printf("2000: %d (ожидается 1)\n", is_leap(2000));
    printf("1900: %d (ожидается 0)\n", is_leap(1900));
    printf("2024: %d (ожидается 1)\n", is_leap(2024));
    printf("2023: %d (ожидается 0)\n", is_leap(2023));
    printf("2100: %d (ожидается 0)\n\n", is_leap(2100));
}

void test_count_days() {
    printf("Тестирование count_days()\n");
    printf("01.01.1970: %ld (ожидается 0)\n", count_days(1, 1, 1970));
    printf("02.01.1970: %ld (ожидается 1)\n", count_days(2, 1, 1970));
    printf("01.01.1971: %ld (ожидается 365)\n", count_days(1, 1, 1971));
    printf("03.05.2026: %ld (ожидается 20575)\n\n", count_days(3, 5, 2026));
}

void test_filter_phones() {
    printf("Тестирование filter_phones()\n");
    struct PhoneBook entries[] = {
        {"Иванов", "6211234567"},
        {"Петров", "1234567890"},
        {"Сидоров", "6219876543"}
    };
    filter_phones(entries, 3);
    printf("\n");
}

int main() {
    test_is_leap();
    test_count_days();
    test_filter_phones();
    return 0;
}
