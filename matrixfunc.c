#include "matrixfunc.h"

// Функция №10: среднее арифметическое каждого столбца
void sred_arif(int *matptr, size_t rows, size_t cols) {
    printf("Среднее арифметическое по столбцам:\n");
    for (size_t j = 0; j < cols; j++) {
        int total = 0;
        for (size_t i = 0; i < rows; i++) {
            total += *(matptr + i * MAX_SIZE + j);
        }
        printf("Столбец %zu: %.2f\n", j, (double)total / rows);
    }
}

// Функция №19: количество положительных элементов матрицы
int plus_len(int *matptr, size_t rows, size_t cols) {
    int count = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if (*(matptr + i * MAX_SIZE + j) > 0) {
                count++;
            }
        }
    }
    return count;
}

// Функция №24: поиск индексов последнего отрицательного элемента при обходе по строкам
// Возвращает 0, если элемент найден, и -1 (код ошибки), если отрицательных элементов нет
int last_minus(int *matptr, size_t rows, size_t cols, size_t *res_row, size_t *res_col) {
    int found = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if (*(matptr + i * MAX_SIZE + j) < 0) {
                *res_row = i;
                *res_col = j;
                found = 1;
            }
        }
    }
    if (!found) {
        return -1; // Код ошибки: элемент не найден
    }
    return 0;
}
