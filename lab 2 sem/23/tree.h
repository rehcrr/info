#pragma once
#include <stdbool.h>

typedef struct node node;

struct node {
    float val;
    node* left;
    node* right;
};

typedef node* tree;

bool is_empty(tree t);
tree empty_tree();
tree build_tree(float val, tree l, tree r);
float root_val(tree t);
tree left(tree t);
tree right(tree t);
void destroy_root(tree t);
bool add(tree* t, float val);
bool delete(tree* t, float val);
bool checking_elements(tree t, int n1, int n2);
void print_tree(tree root);