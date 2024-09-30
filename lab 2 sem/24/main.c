#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Выражение (a + b)^2
    char expression[] = "(a + b) ^ 2";

    printf("Исходное выражение: %s\n", expression);
    TreeNode *root = constructTree(expression);
    printf("Дерево выражения (симметричный обход): ");
    inorderTraversal(root);
    printf("\n");