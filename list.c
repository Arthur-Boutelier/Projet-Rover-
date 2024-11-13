#include "list.h"
#include "tree.h"
#include <stdlib.h>

t_cell_move *create_cell_move(t_move val)
{
    t_cell_move *new_cell = NULL;

    new_cell = malloc(1 * sizeof(t_cell_move));

    new_cell->value = val;
    new_cell->next = NULL;

    return new_cell;
}

t_cell_son *create_cell_son(t_node* val)
{
    t_cell_son *new_cell = NULL;

    new_cell = malloc(1 * sizeof(t_cell_son));

    new_cell->curr_node = val;
    new_cell->next = NULL;

    return new_cell;
}

void addHead_cell_move(t_list_move *list, t_move val)
{
    t_cell_move *newcell;
    newcell = create_cell_move(val);

    newcell->next = list->head;
    list->head = newcell;
}

void addHead_cell_son(t_list_son *list, t_node* val)
{
    t_cell_son *newcell;
    newcell = create_cell_son(val);

    newcell->next = list->head;
    list->head = newcell;
}

t_list_move* create_empty_list_move()
{
    t_list_move *new_list = malloc(sizeof(t_list_move));
    new_list->head = NULL;
    return new_list;
}

t_list_son* create_empty_list_son()
{
    t_list_son *new_list = malloc(sizeof(t_list_son));
    new_list->head = NULL;

    return new_list;
}