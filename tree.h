
#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H
#include "loc.h"
#include "list.h"
#include "moves.h"
#include "map.h"


typedef struct s_node{
    int value;
    t_move * move;
    t_list_move * available_move;
    t_list_son * son;
    t_localisation loc;
    t_map map;
} t_node;

typedef struct s_tree
{
    t_node* root;
} t_tree;

t_tree * create_empty_tree();
t_node * create_empty_node();
void fill_node(t_node * node, int value, t_move * move, t_list_move* available_move, t_localisation loc, t_map map);
t_tree * creating_tree(t_list_move * available_move, int depht, t_localisation initial_position, t_map map);
void creating_tree_node(t_node * node, int depht);
t_list_move * find_optimal_move(t_localisation loc, t_list_move * available_move, t_map map);
t_node * create_node_son(t_node * curr_node, t_localisation new_loc, t_list_move * new_list_move, t_move * curr_move);

#endif //UNTITLED1_TREE_H
