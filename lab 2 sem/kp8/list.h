#pragma once

#include <stdbool.h>

typedef struct Node {
    int data;           
    struct Node* next;  
} Node;

Node* create_node(int data);
void append(Node** head, int data);
void print_list(Node* head);
void free_list(Node* head);
