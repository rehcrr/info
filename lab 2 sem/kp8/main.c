#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "operations.h"

void display_menu() {
    printf("\nМеню:\n");
    printf("1. Печать списка\n");
    printf("2. Вставка элемента\n");
    printf("3. Выполнить попарный обмен значениями\n");
    printf("4. Развернуть список\n");
    printf("5. Выход\n");
    printf("Выберите действие: ");
}

int main() {
    Node* head = NULL;
    int choice, data;

    FILE *output_file = fopen("output.txt", "w");

    if (!output_file) {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    while (true) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Список: ");
                print_list(head);
                fprintf(output_file, "Список: ");
                Node* temp = head;
                while (temp != NULL) {
                    fprintf(output_file, "%d ", temp->data);
                    temp = temp->next;
                }
                fprintf(output_file, "\n");
                break;
            case 2:
                printf("Введите машинное слово для вставки: ");
                scanf("%d", &data);
                append(&head, data);
                break;
            case 3:
                swap_pairs(head);
                printf("Попарный обмен значениями выполнен.\n");
                fprintf(output_file, "Попарный обмен значениями выполнен.\n");
                break;
            case 4:
                reverse_list(&head);
                printf("Список был развернут.\n");
                fprintf(output_file, "Список был развернут.\n");
                break;
            case 5:
                free_list(head);
                printf("Выход из программы.\n");
                fclose(output_file);
                return 0;
            default:
                printf("Неверный выбор, попробуйте снова.\n");
        }
    }
}
