#include "list.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

t_cell_move *create_cell_move(t_move val)
{
    t_cell_move *new_cell = (t_cell_move*)malloc(sizeof(t_cell_move));
    new_cell->value = val;
    new_cell->next = NULL;

    return new_cell;
}

t_cell_son *create_cell_son(t_node* val)
{
    t_cell_son *new_cell = (t_cell_son*)malloc(sizeof(t_cell_son));
    new_cell->node = val;
    new_cell->next = NULL;
    return new_cell;
}

void addHead_cell_move(t_list_move *list, t_move val)
{
    t_cell_move *newcell;
    newcell = create_cell_move(val);
    if(list->head == NULL)
    {
        list->head = newcell;
        return;
    }
    newcell->next = list->head;
    list->head = newcell;
}

void addHead_cell_son(t_list_son *list, t_node* val)
{
    t_cell_son *newcell = create_cell_son(val);

    if (list->head != NULL) {
        newcell->next = list->head;
        list->head = newcell;
    }
    else {
        list->head = newcell;
    }

}

t_list_move* create_empty_list_move()
{
    t_list_move *new_list = (t_list_move*)malloc(sizeof(t_list_move));
    new_list->head = NULL;
    return new_list;
}

t_list_son* create_empty_list_son()
{
    t_list_son *new_list = (t_list_son*)malloc(sizeof(t_list_son));
    new_list->head = NULL;

    return new_list;
}

t_list_move* removeVal_move(t_list_move *list, t_move val) {
    t_list_move *new_list = create_empty_list_move();
    t_cell_move *current = list->head;
    int task_done = 0;
    while (current != NULL) {
        if (task_done || current->value != val)
            addHead_cell_move(new_list, current->value);
        else
            task_done = 1;
        current = current->next;
    }

    return new_list;
}

t_cell_freemove *create_cell_freemove(t_move val, int nb){
    t_cell_freemove *new_cell = (t_cell_freemove*)malloc(sizeof(t_cell_freemove));
    new_cell->numberofmoveleft = nb;
    new_cell->value = val;
    new_cell->next = NULL;

    return new_cell;
}

void addHead_cell_freemove(t_list_freemove *list, t_move val, int nb){
    t_cell_freemove *new_cell = create_cell_freemove(val, nb);

    new_cell->next = list->head;
    list->head = new_cell;
}

t_list_freemove* create_empty_list_freemove(){
    t_list_freemove *new_list = (t_list_freemove*)malloc(sizeof(t_list_freemove));
    new_list->head = NULL;
    return new_list;
}

void affichage_t_list_freemove(t_list_freemove* list){
    t_cell_freemove* current = list->head;
    while(current->next != NULL){
        printf("%d \n", current->numberofmoveleft);
        printf("%s \n", getMoveAsString(current->value));
        printf("\n");
        current = current->next;
    }
}

void affichage_t_list_move(t_list_move* list) {
    t_cell_move *current = list->head;
    while (current != NULL) {
        printf("%s \n", getMoveAsString(current->value));
        current = current->next;
    }
}

void del_list_son(t_list_son * list_son){
    t_cell_son * curr = list_son->head;
    t_cell_son * next;
    while(curr != NULL){
        next = curr->next;
        free(curr);
        curr = next;
    }
    free(list_son);
}


void del_list_move(t_list_move * list_move){
    t_cell_move * curr = list_move->head;
    t_cell_move * next;
    while(curr != NULL){
        next = curr->next;
        free(curr);
        curr = next;
    }
    free(list_move);
}
