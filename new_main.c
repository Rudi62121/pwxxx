case 'd':
case 'e':
case 'f': {
    if (!is_filled) {
        printf("Сначала задайте размер и заполните матрицу (пункты a и b).\n");
        break;
    }
    int *matptr = &mat[0][0];
    if (ch == 'd') {
        sred_arif(matptr, rows, cols);
    } else if (ch == 'e') {
        int count = plus_len(matptr, rows, cols);
        printf("Количество положительных элементов: %d\n", count);
    } else if (ch == 'f') {
        size_t r_idx, c_idx;
        if (last_minus(matptr, rows, cols, &r_idx, &c_idx) == 0) {
            printf("Индексы последнего отрицательного элемента: строка %zu, столбец %zu\n", r_idx, c_idx);
        } else {
            printf("Отрицательные элементы в матрице не найдены.\n");
        }
    }
    break;
}
