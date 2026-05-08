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
static int cmp_by_date_hook(const void *a, const void *b);

void test_person_output() {
    printf("Тестирование вывода студентов (задача 3)\n");
    struct PERSON test_arr[] = {
        {"Иванов И.И.", "ФИТ", "107", {2021, 9, 1}},
        {"Петров П.П.", "ФПМИ", "205", {2022, 7, 15}},
        {"Сидоров С.С.", "ФИТ", "107", {2020, 8, 20}},
        {"Козлов А.В.", "ФПМИ", "205", {2022, 7, 10}}
    };
    int n = sizeof(test_arr) / sizeof(test_arr[0]);
    qsort(test_arr, n, sizeof(struct PERSON), cmp_by_date_hook);
    print_persons_sorted(test_arr, n);
    printf("\n");
}

static int cmp_by_date_hook(const void *a, const void *b) {
    const struct PERSON *pa = a, *pb = b;
    if (pa->DATE.year != pb->DATE.year) return pa->DATE.year - pb->DATE.year;
    if (pa->DATE.month != pb->DATE.month) return pa->DATE.month - pb->DATE.month;
    return pa->DATE.day - pb->DATE.day;
}

void test_filter_phones() {
    printf("Тестирование filter_phones()\n");
    struct PhoneOwner entries[] = {
        {"Иванов", "Иван", "Иванович", "220000", "Беларусь", "Минская", "", "Минск", "Ленина", "1", "10", "6211234567"},
        {"Петров", "Петр", "Петрович", "220000", "Беларусь", "Минская", "", "Минск", "Пушкина", "2", "20", "1234567890"},
        {"Сидоров", "Сидор", "Сидорович", "220000", "Беларусь", "Минская", "", "Минск", "Гагарина", "3", "30", "6219876543"}
    };
    filter_phones(entries, 3);
    printf("\n");
}

void test_all() {
    test_is_leap();
    test_count_days();
    test_person_output();
    test_filter_phones();
}

void task1_interactive() {
    int d1, m1, y1, d2, m2, y2;
    printf("Введите первую дату (день месяц год): ");
    scanf("%d %d %d", &d1, &m1, &y1);
    printf("Введите вторую дату (день месяц год): ");
    scanf("%d %d %d", &d2, &m2, &y2);

    long days1 = count_days(d1, m1, y1);
    long days2 = count_days(d2, m2, y2);
    long diff = days2 - days1;
    if (diff < 0) diff = -diff;
    printf("Разница между датами: %ld дней\n", diff);
}

void task3_interactive() {
    struct PERSON vuz[10];
    printf("Введите данные о 10 студентах (Фамилия И.О., факультет, группа, год месяц день):\n");
    for (int i = 0; i < 10; i++) {
        printf("Студент %d:\n", i+1);
        printf("  Фамилия И.О.: ");
        scanf(" %[^\n]", vuz[i].Name);
        printf("  Факультет: ");
        scanf(" %[^\n]", vuz[i].FAC);
        printf("  Группа: ");
        scanf(" %[^\n]", vuz[i].GROUP);
        printf("  Дата поступления (год месяц день): ");
        scanf("%d %d %d", &vuz[i].DATE.year, &vuz[i].DATE.month, &vuz[i].DATE.day);
    }
    qsort(vuz, 10, sizeof(struct PERSON), cmp_by_date_hook);
    print_persons_sorted(vuz, 10);
}

void task4_interactive() {
    int n;
    printf("Сколько владельцев телефонов вы хотите ввести? ");
    scanf("%d", &n);
    struct PhoneOwner *owners = malloc(n * sizeof(struct PhoneOwner));
    if (!owners) {
        fprintf(stderr, "Ошибка памяти\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("Владелец %d:\n", i+1);
        printf("  Фамилия: "); scanf(" %[^\n]", owners[i].surname);
        printf("  Имя: "); scanf(" %[^\n]", owners[i].name);
        printf("  Отчество: "); scanf(" %[^\n]", owners[i].patronymic);
        printf("  Почтовый индекс: "); scanf(" %[^\n]", owners[i].postal_code);
        printf("  Страна: "); scanf(" %[^\n]", owners[i].country);
        printf("  Область: "); scanf(" %[^\n]", owners[i].region);
        printf("  Район: "); scanf(" %[^\n]", owners[i].district);
        printf("  Город: "); scanf(" %[^\n]", owners[i].city);
        printf("  Улица: "); scanf(" %[^\n]", owners[i].street);
        printf("  Дом: "); scanf(" %[^\n]", owners[i].house);
        printf("  Квартира: "); scanf(" %[^\n]", owners[i].apartment);
        printf("  Номер телефона: "); scanf(" %[^\n]", owners[i].phone);
    }
    filter_phones(owners, n);
    free(owners);
}

int main() {
    int choice;
    do {
        printf("1 - Задача 1\n");
        printf("2 - Задача 3\n");
        printf("3 - Задача 4\n");
        printf("4 - Запустить все тесты\n");
        printf("0 - Выход\n");
        printf("выбор: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: task1_interactive(); break;
            case 2: task3_interactive(); break;
            case 3: task4_interactive(); break;
            case 4: test_all(); break;
            case 0: printf("выход\n"); break;
            default: printf("Неверный выбор.\n");
        }
    } while (choice != 0);

    return 0;
}
