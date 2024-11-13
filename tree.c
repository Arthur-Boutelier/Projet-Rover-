#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "list.h"
#include "moves.h"


t_tree * create_empty_tree(){
    t_tree * new_tree = (t_tree *) malloc(sizeof(t_tree));
    new_tree->root = NULL;
    return new_tree;
}


t_node * create_empty_node(){
    t_node * new_node = (t_node*)malloc(sizeof(t_node));
    return new_node;
}

void fill_node(t_node * node, int value, t_move* move, t_list_move* available_move, t_localisation loc, t_map map){
    node->value = value;
    node->move = move;
    node->available_move = available_move;
    node->loc = loc;
    node->son = NULL;
    node-> map = map;
}

t_tree* creating_tree(t_list_move * available_move, int depht, t_localisation initial_position, t_map map){
    t_tree * tree = create_empty_tree();
    t_node * root = create_empty_node();
    fill_node(root, map.costs[initial_position.pos.x][initial_position.pos.y], NULL, available_move, initial_position, map);
    tree->root = root;
    creating_tree_node(tree->root, depht);
    return tree;
}
/*
t_list_move * find_optimal_move(t_localisation loc, t_list_move * available_move, t_map map){
    tab_move_opti =
    int min =
}
/*void creating_tree_node(t_node * node, int depht);
 */