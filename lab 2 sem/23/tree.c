#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

tree empty_tree() {
    return NULL;
}

tree build_tree(float val, tree l, tree r) {
    tree new_node = (tree)malloc(sizeof(node));
    new_node->val = val;
    new_node->left = l;
    new_node->right = r;
    return new_node;
}

bool is_empty(tree t) {
    return t == NULL;
}

float root_val(tree t) {
    if (t == NULL) {
        printf("Ошибка: пустое дерево.\n");
        return -1;
    }
    return t->val;
}

tree left(tree t) {
    if (t != NULL) {
        return t->left;
    }
    return NULL;
}

tree right(tree t) {
    if (t != NULL) {
        return t->right;
    }
    return NULL;
}

static bool check_level(tree t, int level, int* leaf_level) {
    if (t == NULL) {
        return true; 
    }

    if (t->left == NULL && t->right == NULL) {
        if (*leaf_level == -1) {
            *leaf_level = level;  
        }
        return level == *leaf_level;
    }

    return check_level(t->left, level + 1, leaf_level) &&
           check_level(t->right, level + 1, leaf_level);
}

bool are_all_leaves_at_same_level(tree t) {
    int leaf_level = -1;
    return check_level(t, 0, &leaf_level);
}

bool add(tree* t, float val){
    tree* place = find(t, val);
    if (*place != NULL){
        return false;
    }
    tree new_node = malloc(sizeof(node));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    *place = new_node;
    return true;
}

bool delete(tree* t, float val){
    tree* place = find(t, val);
    if (*place == NULL) {
        return false;
    }
    if ((*place)->left == NULL && (*place)->right == NULL){
        free(*place);
        *place = NULL;
    } else if ((*place)->left == NULL){
        tree new_right = (*place)->right;
        free(*place);
        *place = new_right;
    } else if ((*place)->right == NULL){
        tree new_left = (*place)->left;
        free(*place);
        *place = new_left;
    } else {
        tree *r = &((*place)->right);
        if ((*r)->left == NULL) {
            tree new_root = *r;
            new_root->left = (*place)->left;
            free(*place);
            *place = new_root;
        } else {
            while ((*r)->left != NULL){
                r = &((*r)->left);
                tree min_r = (*r);
                *r = (*r)->right;
                min_r->right = (*place)->right;
                min_r->left = (*place)->left;
                free(*place);
                *place = min_r;
            }
        }
    }
    return true;
}

bool checking_elements(tree t, int start, int end) {
    if (t == NULL) {
        return true;
    }
    if (t->left == NULL && t->right == NULL) {
        if (t->val < start || t->val > end){
        return false;
        }
    }
    return checking_elements(t->left, start, end) && checking_elements(t->right, start, end);
}

static void _print_tree(tree root, int n) {
    if (root == NULL) {
        return;
    }
    _print_tree(root->right, n + 1);
    for (int i = 0; i < n; i++) {
        printf("\t");
    }
    printf("%.3f\n", root->val);
    _print_tree(root->left, n + 1);
}

void print_tree(tree root) {
    _print_tree(root, 1);
}