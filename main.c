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

// --- ЗАДАНИЕ 4 (Модифицированное) ---
void zadanie4(void) {
    printf("\n=========== ЗАДАНИЕ 4 ===========\n");
    int rows, cols;
    int prob_one;

    printf("Введите количество строк: ");
    if (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Ошибка ввода строк!\n");
        return;
    }

    printf("Введите количество столбцов: ");
    if (scanf("%d", &cols) != 1 || cols <= 0) {
        printf("Ошибка ввода столбцов!\n");
        return;
    }

    printf("Введите вероятность появления '1' в процентах (0 - 100): ");
    if (scanf("%d", &prob_one) != 1 || prob_one < 0 || prob_one > 100) {
        printf("Некорректная вероятность! Должна быть от 0 до 100.\n");
        return;
    }

    // Динамическое выделение памяти под двумерный массив
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        printf("Ошибка выделения памяти!\n");
        return;
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Ошибка выделения памяти для строки %d!\n", i);
            return;
        }
    }

    // Заполнение 0 и 1 с заданной вероятностью
    srand((unsigned int)time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int random_val = rand() % 100; // Число от 0 до 99
            matrix[i][j] = (random_val < prob_one) ? 1 : 0;
        }
    }

    // Вывод матрицы
    printf("\nСгенерированный массив (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }

    // Подсчет сумм по строкам
    printf("\nСуммы по строкам:\n");
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        printf("Строка %d: %d\n", i + 1, sum);
    }

    // Подсчет сумм по столбцам
    printf("\nСуммы по столбцам:\n");
    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += matrix[i][j];
        }
        printf("Столбец %d: %d\n", j + 1, sum);
    }

    // Освобождение динамической памяти
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// --- ЗАДАНИЕ 5 (Модифицированное) ---
struct student {
    char famil[20];
    char name[20];
    char facult[20];
    int Nomzach;
};

void zadanie5(void) {
    printf("\n=========== ЗАДАНИЕ 5 ===========\n");
    struct student stud[4] = {
        {"Иванов", "Иван", "ВТ", 1001},
        {"Иванова", "Анна", "ИВТ", 1002},
        {"Петров", "Петр", "ФИИТ", 1003},
        {"Сидоров", "Алексей", "ВТ", 1004}
    };

    char query[20];
    printf("База студентов загружена.\n");
    printf("Введите подстроку для поиска (по любому полю): ");
    scanf("%19s", query);

    int found_count = 0;

    for (int i = 0; i < 4; i++) {
        char zach_str[20];
        // Преобразуем номер зачетки в строку для поиска по подстроке
        sprintf(zach_str, "%d", stud[i].Nomzach);

        // Поиск подстроки во всех текстовых и числовых полях
        if (strstr(stud[i].famil, query) != NULL ||
            strstr(stud[i].name, query) != NULL ||
            strstr(stud[i].facult, query) != NULL ||
            strstr(zach_str, query) != NULL) {

            found_count++;
            printf("\n--- Найден студент #%d ---\n", found_count);
            printf("Фамилия:       %s\n", stud[i].famil);
            printf("Имя:           %s\n", stud[i].name);
            printf("Факультет:     %s\n", stud[i].facult);
            printf("Номер зачетки: %d\n", stud[i].Nomzach);
        }
    }

    if (found_count == 0) {
        printf("\nСтуденты по запросу \"%s\" не найдены.\n", query);
    } else {
        printf("\nВсего найдено совпадений: %d\n", found_count);
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
        printf("2. Задание 4 (Двумерный массив 0/1 с вероятностью)\n");
        printf("3. Задание 5 (Поиск по подстроке во всех полях)\n");
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
