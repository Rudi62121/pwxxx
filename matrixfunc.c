#include "matrixfunc.h"

int sred_arif(int *matptr, size_t rows, size_t cols) {
    printf("srednee arifmeticheskoe:\n");
    for (int column = 0; column < cols; column++) {
        int total = 0;
        for (int i = 0; i < rows; i++) {
            //printf("%d", *(matptr + i*cols + column));
            total += *(matptr + i*cols + column);
        }
        if (total == 0) {
            printf("error 404: not found");
            return 0;
        }
        printf("column %d: %d\n", column+1, total/rows);
    }
    printf("\n\n");
    return 0;
}

int plus_len(int *matptr, size_t rows, size_t cols) {
    int total = 0;
    for (int i = 0; i < rows*cols; i++) {
        if (*(matptr + i) > 0) {
            total += 1;
        }
    }
    if (total == 0) {
        printf("error 404: not found");
        return 0;
    }
    printf("all polozitelnie: %d\n", total);
    return 0;
}

int last_minus(int *matptr, size_t rows, size_t cols) {
    int last = 0;
    for (int i = 0; i < rows*cols; i++) {
        if (*(matptr + i) < 0) {
            last = *(matptr + i);
        }
    }
    if (last == 0) {
        printf("error 404: not found");
        return 0;
    }
    printf("last minus: %d", last);
    return 0;
}