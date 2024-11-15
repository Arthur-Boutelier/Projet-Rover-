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

t_tree* creating_tree(t_list_move * available_move, int depth, t_localisation initial_position, t_map map){
    t_tree * tree = create_empty_tree();
    t_node * root = create_empty_node();
    fill_node(root, map.costs[initial_position.pos.x][initial_position.pos.y], NULL, available_move, initial_position, map);
    tree->root = root;
    creating_tree_node(tree->root, depth);
    return tree;
}

t_list_move * find_optimal_move(t_localisation loc, t_list_move * available_move, t_map map){
    t_move tab_move_opti[10];
    int logical_size = 0;
    int min = 100000;
    t_cell_move * curr = available_move -> head;
    while (curr != NULL){
        t_localisation new_loc = move(loc, curr->value);
        if (min == map.costs[new_loc.pos.x][new_loc.pos.y]){
            int occ = 0;
            for (int i = 0; i < logical_size; i++){
                if (curr->value == tab_move_opti[i])
                    occ ++;
            }
            if (occ == 0){
                tab_move_opti[logical_size] = curr->value;
                logical_size++;
            }
            min = map.costs[new_loc.pos.x][new_loc.pos.y];
        }
        else if(min > map.costs[new_loc.pos.x][new_loc.pos.y]){
            tab_move_opti[0] = curr->value;
            logical_size = 1;
        }
        curr = curr->next;
    }
    t_list_move * opti_move = create_empty_list_move();
    for (int i = 0; i<logical_size; i++)
        addHead_cell_move(opti_move, tab_move_opti[i]);
    return opti_move;
}

void creating_tree_node(t_node * node, int depth){
    if (depth > 0){

    }
}
#define min(a,b) ((a)>(b)?(a):(b))

t_list_move* find_shortest_patch(t_tree* tree){

}
