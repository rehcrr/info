#include <stdio.h>
#include "operations.h"

void swap_pairs(Node* head) {
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        int temp_data = temp->data;
        temp->data = temp->next->data;
        temp->next->data = temp_data;
        temp = temp->next->next;
    }
}

void reverse_list(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
