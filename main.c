#include "matrixfunc.h"

#define MAX_SIZE 20

// Вспомогательная функция очистки буфера при ошибке ввода
void clear_input(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    int mat[MAX_SIZE][MAX_SIZE] = {0};
    size_t rows = 0;
    size_t cols = 0;
    int is_sized = 0;  // Флаг: задан ли размер (пункт a)
    int is_filled = 0; // Флаг: заполнена ли матрица (пункт b)

    printf("a - Задать размер матрицы (строки, столбцы)\n");
    printf("b - Заполнить матрицу\n");
    printf("c - Представление матрицы (значения, адреса элементов)\n");
    printf("d - Вычисление среднего арифметического элементов каждого столбца матрицы\n");
    printf("e - Определение количества положительных элементов матрицы\n");
    printf("f - Поиск индексов последнего отрицательного элемента матрицы при обходе по строкам\n");
    printf("g - Выход\n");

    char ch;
    int out;

    while (1) {
        printf("\nВыберите пункт: ");
        out = scanf(" %c", &ch);

        if (out == EOF) {
            printf("\nЗавершение работы (EOF).\n");
            break;
        }

        // Проверяем, нет ли лишних символов после буквы пункта
        int extra = 0;
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
            if (c != ' ' && c != '\t') extra = 1;
        }
        if (extra) {
            printf("Ошибка: введите только одну букву от a до g.\n");
            continue;
        }

        switch (ch) {
            case 'a': {
                int r, cl;
                printf("Введите количество строк (1-%d): ", MAX_SIZE);
                int res1 = scanf("%d", &r);
                if (res1 == EOF) return 0;
                if (res1 != 1 || r <= 0 || r > MAX_SIZE) {
                    printf("Ошибка: некорректное количество строк.\n");
                    clear_input();
                    break;
                }
                clear_input();

                printf("Введите количество столбцов (1-%d): ", MAX_SIZE);
                int res2 = scanf("%d", &cl);
                if (res2 == EOF) return 0;
                if (res2 != 1 || cl <= 0 || cl > MAX_SIZE) {
                    printf("Ошибка: некорректное количество столбцов.\n");
                    clear_input();
                    break;
                }
                clear_input();

                rows = (size_t)r;
                cols = (size_t)cl;
                is_sized = 1;
                is_filled = 0; // При смене размера матрицу нужно заполнить заново
                printf("Размер установлен: %zu x %zu\n", rows, cols);
                break;
            }

            case 'b': {
                if (!is_sized) {
                    printf("Сначала задайте размер матрицы (пункт a).\n");
                    break;
                }
                printf("Введите элементы матрицы (%zu x %zu):\n", rows, cols);
                int error = 0;
                for (size_t i = 0; i < rows && !error; i++) {
                    for (size_t j = 0; j < cols; j++) {
                        printf("Элемент [%zu][%zu]: ", i, j);
                        int res = scanf("%d", (*(mat + i) + j));
                        if (res == EOF) return 0;
                        if (res != 1) {
                            printf("Ошибка: введите целое число.\n");
                            clear_input();
                            error = 1;
                            break;
                        }
                        clear_input();
                    }
                }
                if (!error) {
                    is_filled = 1;
                    printf("Матрица успешно заполнена.\n");
                }
                break;
            }

            case 'c': {
                if (!is_filled) {
                    printf("Сначала задайте размер и заполните матрицу (пункты a и b).\n");
                    break;
                }
                printf("Матрица (значение [адрес в памяти]):\n");
                for (size_t i = 0; i < rows; i++) {
                    for (size_t j = 0; j < cols; j++) {
                        int *elem_ptr = (*(mat + i) + j);
                        printf("%4d [%p]  ", *elem_ptr, (void *)elem_ptr);
                    }
                    printf("\n");
                }
                break;
            }

            case 'd':
            case 'e':
            case 'f': {
                if (!is_filled) {
                    printf("Сначала задайте размер и заполните матрицу (пункты a и b).\n");
                    break;
                }
                // Передаём указатель на первый элемент &mat[0][0]
                int *matptr = &mat[0][0];
                if (ch == 'd') sred_arif(matptr, rows, cols);
                if (ch == 'e') plus_len(matptr, rows, cols);
                if (ch == 'f') last_minus(matptr, rows, cols);
                break;
            }

            case 'g':
                printf("Выход из программы.\n");
                return 0;

            default:
                printf("Некорректный пункт меню. Выберите букву от a до g.\n");
                break;
        }
    }

    return 0;
}
