#include <stdlib.h>
#include "tree.h"


t_tree * create_empty_tree(){
    t_tree * new_tree = (t_tree *) malloc(sizeof(t_tree));
    new_tree->root = NULL;
    return new_tree;
}


t_node * create_empty_node(){
    t_node * new_node = (t_node*)malloc(sizeof(t_node));
    return new_node;
}

void fill_node(t_node * node, int value, t_move move, t_list_move* available_move, t_localisation loc, t_map map){
    node->value = value;
    node->move = move;
    node->available_move = available_move;
    node->loc = loc;
    node->son = create_empty_list_son();
    node-> map = map;
    node->parent = NULL;
}

t_tree* creating_tree(t_list_move * available_move, int depth, t_localisation initial_position, t_map map){
    t_tree * tree = create_empty_tree();
    t_node * root = create_empty_node();
    fill_node(root, map.costs[initial_position.pos.y][initial_position.pos.x], STILL, available_move, initial_position, map);
    tree->root = root;
    creating_tree_node(tree->root, depth);
    return tree;
}

t_list_move * find_optimal_move(t_localisation loc, t_list_move * available_move, t_map map){
    t_move tab_move_opti[10];
    int logical_size = 0;
    int min = map.costs[loc.pos.y][loc.pos.x];
    t_cell_move * curr = available_move -> head;
    while (curr != NULL) {
        t_move true_move = update_move_soil(curr->value, map.soils[loc.pos.y][loc.pos.x]);
        t_localisation new_loc = move(loc, true_move);
        if (isValidLocalisation(new_loc.pos, map.x_max, map.y_max) && not_passing_crevasse(curr->value, map, loc)){
            if (min == map.costs[new_loc.pos.y][new_loc.pos.x]){
                int occ = 0;
                for (int i = 0; i < logical_size; i++) {
                    if (curr->value == tab_move_opti[i]){
                        occ++;
                    }
                }
                if (occ == 0) {
                    tab_move_opti[logical_size] = curr->value;
                    logical_size++;
                }
            }
            else if (min > map.costs[new_loc.pos.y][new_loc.pos.x]) {
                tab_move_opti[0] = curr->value;
                logical_size = 1;
                min = map.costs[new_loc.pos.y][new_loc.pos.x];
            }
        }
        curr = curr->next;
    }
    t_list_move * opti_move = create_empty_list_move();
    for (int i = 0; i<logical_size; i++){
        addHead_cell_move(opti_move, tab_move_opti[i]);
    }
    return opti_move;
}

t_node * create_node_son(t_node * curr_node, t_localisation new_loc, t_list_move * new_list_move, t_move curr_move){
    t_node * new_node = create_empty_node();
    new_node->loc = new_loc;
    new_node->available_move = new_list_move;
    new_node->map = curr_node->map;
    new_node->move = curr_move;
    new_node->value = new_node->map.costs[new_loc.pos.y][new_loc.pos.x];
    new_node->son = create_empty_list_son();
    new_node->parent = curr_node;
    return new_node;
}

void creating_tree_node(t_node * node, int depth){
    if (depth > 0){
        t_list_move * optimal_move = find_optimal_move(node->loc, node->available_move, node->map);
        t_cell_move * curr = optimal_move->head;
        while (curr != NULL){
            t_list_move * new_available_move = removeVal_move(node->available_move, curr->value);
            t_localisation new_loc = move(node->loc, update_move_soil(curr->value, node->map.soils[node->loc.pos.y][node->loc.pos.x]));
            t_node* new_node = create_node_son(node, new_loc, new_available_move, curr->value);
            addHead_cell_son(node->son, new_node);
            curr = curr->next;
        }
        t_cell_son * actual_son = node->son->head;
        del_list_move(optimal_move);
        while (actual_son != NULL){
            creating_tree_node(actual_son->node, depth-1);
            actual_son = actual_son->next;
        }
    }
}

t_node * find_min_node_tree(t_tree tree){
    return find_min_node(tree.root);
}
t_node * find_min_node(t_node * node){
    if (node->son->head == NULL || node->value == 0)
        return node;
    t_cell_son * curr = node->son->head;
    t_node * min_node = curr->node;
    while (curr != NULL){
        t_node* inter_min_node = find_min_node(curr->node);
        if (min_node->value > inter_min_node->value)
            min_node = inter_min_node;
        else if (min_node->value == inter_min_node->value){
            if(depth_node(min_node)> depth_node(inter_min_node))
                min_node = inter_min_node;
        }
        curr = curr->next;
    }

    return min_node;
}

t_list_move * recover_move_node(t_node * node){
    t_list_move * reco_move = create_empty_list_move();
    t_node * curr = node;
    while (curr != NULL){
            addHead_cell_move(reco_move, curr->move);
        curr = curr->parent;
    }
    return reco_move;
}

int depth_node(t_node* node){
    int i = 1;
    t_node * curr = node->parent;
    while (curr != NULL){
        curr = curr->parent;
        i++;
    }
    return i;
}

void del_node(t_node* node){
    t_cell_son * curr = node->son->head;
    while (curr != NULL){
        del_node(curr->node);
        curr = curr->next;
    }
    del_list_son(node->son);
    del_list_move(node->available_move);
    free(node);
}

void del_tree(t_tree* tree){
    del_node(tree->root);
    free(tree);
}
