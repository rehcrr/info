#include <stdio.h>
#include "sort.h"

void selection_sort(int keys[], char *data[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (keys[j] < keys[min_idx]) {
                min_idx = j;
            }
        }
        // Меняем местами ключи
        int temp_key = keys[i];
        keys[i] = keys[min_idx];
        keys[min_idx] = temp_key;

        // Меняем местами данные
        char *temp_data = data[i];
        data[i] = data[min_idx];
        data[min_idx] = temp_data;
    }
}

int linear_search(int keys[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (keys[i] == key) {
            return i;
        }
    }
    return -1;
}
