#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// --- ЗАДАНИЕ 1: Поиск разницы между max и min ---
void zadanie1(int* a, int n) {
    int min = a[0];
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) min = a[i];
        if (a[i] > max) max = a[i];
    }
    printf("Максимальный элемент: %d\n", max);
    printf("Минимальный элемент: %d\n", min);
    printf("Разница (max - min): %d\n", max - min);
}

// --- ЗАДАНИЯ 1, 2 и 3 ---
void zadanie1_2_3(void) {
    printf("\n=========== ЗАДАНИЯ 1, 2 и 3 ===========\n");
    int n;
    printf("Введите размер одномерного массива: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Ошибка: введен некорректный размер!\n");
        return;
    }

    int* a = (int*)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Ошибка выделения памяти!\n");
        return;
    }

    srand((unsigned int)time(NULL));
    printf("Сгенерированный массив: ");
    for (int i = 0; i < n; i++) {
        a[i] = 10 + rand() % 90;
        printf("%d ", a[i]);
    }
    printf("\n");

    zadanie1(a, n);

    free(a);
}

// --- ЗАДАНИЕ 4 ---
void zadanie4(void) {
    printf("\n=========== ЗАДАНИЕ 4 ===========\n");
    int matrix[3][4] = {
        {1, 3, 6, 2},
        {3, 8, 3, 8},
        {8, 5, 5, 2}
    };

    printf("Сгенерированный двумерный массив (3x4):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nСуммы по строкам:\n");
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += matrix[i][j];
        }
        printf("Строка %d: %d\n", i + 1, sum);
    }

    printf("\nСуммы по столбцам:\n");
    for (int j = 0; j < 4; j++) {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += matrix[i][j];
        }
        printf("Столбец %d: %d\n", j + 1, sum);
    }
}

// --- ЗАДАНИЕ 5 ---
struct student {
    char famil[20];
    char name[20];
    char facult[20];
    int Nomzach;
};

void zadanie5(void) {
    printf("\n=========== ЗАДАНИЕ 5 ===========\n");
    struct student stud[3] = {
        {"Иванов", "Иван", "ВТ", 1001},
        {"Петров", "Петр", "ФИИТ", 1002},
        {"Сидоров", "Алексей", "ВТ", 1003}
    };

    char search_famil[20];
    printf("База студентов загружена.\n");
    printf("Введите фамилию для поиска (например, Иванов): ");
    scanf("%19s", search_famil);

    int found = 0;
    for (int i = 0; i < 3; i++) {
        if (strcmp(stud[i].famil, search_famil) == 0) {
            printf("\n--- Студент найден ---\n");
            printf("Фамилия: %s\n", stud[i].famil);
            printf("Имя: %s\n", stud[i].name);
            printf("Факультет: %s\n", stud[i].facult);
            printf("Номер зачетки: %d\n", stud[i].Nomzach);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Студент с фамилией \"%s\" не найден.\n", search_famil);
    }
}

int main(void) {
    
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int choice;
    do {
        printf("\n=====================================\n");
        printf("        ЛАБОРАТОРНАЯ РАБОТА № 1      \n");
        printf("=====================================\n");
        printf("1. Задания 1, 2, 3 (Одномерный массив)\n");
        printf("2. Задание 4 (Двумерный массив)\n");
        printf("3. Задание 5 (Поиск студента)\n");
        printf("0. Выход\n");
        printf("Выберите пункт меню: ");

        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
        case 1:
            zadanie1_2_3();
            break;
        case 2:
            zadanie4();
            break;
        case 3:
            zadanie5();
            break;
        case 0:
            printf("\nПрограмма завершена. До свидания!\n");
            break;
        default:
            printf("\nНеверный пункт! Попробуйте снова.\n");
        }
    } while (choice != 0);

    return 0;
}