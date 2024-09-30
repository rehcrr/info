#include <stdio.h>
#include "sum.h"
#include "tree.h"


void razlozhit_kvadrat_summy(const char *expression) {
    printf("Исходное выражение: %s\n", expression); 
 
    TreeNode *root = constructTree(expression);

    printf("Дерево выражения (симметричный обход): ");
    inorderTraversal(root);
    printf("\n");
    
    lexicographicalSort(root);
    
    printf("Преобразованное дерево выражения (симметричный обход): ");
    inorderTraversal(root);
    printf("\n");
    
    freeTree(root);
}
