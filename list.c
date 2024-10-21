#include "list.h"
#include <stdlib.h>

void insert_node(t_list* list,  int value, char* action){
    t_node_tree* new_node = create_node_list(value, action);
    if (list->head == NULL)
        list->head = new_node;
    else{
        t_node_tree* current = list->head;
        while (current->next != NULL)
            current = current->next;
        current->next = new_node;
    }
}






