#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define MAX_DATA 100

int main() {
    int keys[MAX_DATA];
    char *data[MAX_DATA];
    int n;

    // Ввод количества элементов
    printf("Введите количество элементов: ");
    scanf("%d", &n);

    // Ввод ключей и соответствующих данных
    for (int i = 0; i < n; i++) {
        data[i] = (char *)malloc(100 * sizeof(char));  // Выделение памяти для строк данных
        printf("Введите ключ и данные для элемента %d: ", i + 1);
        scanf("%d %[^\n]", &keys[i], data[i]);  // Чтение ключа и строки данных
    }

    // Сортировка данных по ключам
    selection_sort(keys, data, n);

    // Ввод ключа для поиска
    int key_to_search;
    printf("Введите ключ для поиска: ");
    scanf("%d", &key_to_search);

    // Поиск ключа
    int index = linear_search(keys, n, key_to_search);

    // Вывод результата в файл
    FILE *output = fopen("output.txt", "w");
    if (output == NULL) {
        printf("Ошибка открытия файла output.txt\n");
        return 1;
    }

    if (index != -1) {
        fprintf(output, "Ключ найден на индексе %d:\nКлюч: %d\nДанные: %s\n", index, keys[index], data[index]);
    } else {
        fprintf(output, "Ключ %d не найден.\n", key_to_search);
    }
    fclose(output);

    // Очистка памяти
    for (int i = 0; i < n; i++) {
        free(data[i]);
    }

    return 0;
}
