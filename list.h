#include "tree.h"
#ifndef UNTITLED1_LIST_H
#define UNTITLED1_LIST_H
typedef struct s_cell_tree{
t_node_n_aire* value;
struct s_cell_tree* next;
} t_cell_tree;

typedef struct s_list{
    t_cell_tree* head;
}t_list_tree;

t_cell_tree* create_cell(int val, char* action);
void insert_cell(t_list_tree* list,  int value, char* action);
#endif //UNTITLED1_LIST_H
