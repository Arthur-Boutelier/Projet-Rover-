
#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H
#include "loc.h"
#include "list.h"
#include "moves.h"


typedef struct s_node{
    int value;
    t_move move;
    t_list_move available_move;
    t_list_son * son;
    t_localisation loc;
} t_node;

typedef struct s_tree
{
    t_node* root;
} t_tree;

t_tree * create_empty_tree();
t_node * create_empty_node();
void fill_node(t_node * node, int value, t_move move, t_list_move available_move, t_localisation loc);
void creating_tree(t_tree * tree, t_list_move * available_move, int depht, t_position initial_position);
void creating_tree_node(t_node * node, int depht);
t_list_move * find_optimal_move(t_localisation loc, t_list_move available_move);

#endif //UNTITLED1_TREE_H
