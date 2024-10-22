#include "list.h"
#include <stdlib.h>


t_cell_tree* create_cell(int val, char* action){
    t_cell_tree * new_cell = (t_cell_tree*) malloc(sizeof(t_cell_tree));
    new_cell->next = NULL;
    new_cell-> value = create_node_n_aire(val, action);
    return new_cell;
}

void insert_cell(t_list_tree * list,  int value, char* action){
    t_cell_tree* new_cell = create_cell(value, action);
    if (list->head == NULL)
        list->head = new_cell;
    else{
        t_cell_tree* current = list->head;
        while (current->next != NULL)
            current = current->next;
        current->next = new_cell;
    }
}

