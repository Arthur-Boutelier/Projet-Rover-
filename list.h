#ifndef UNTITLED1_LIST_H
#define UNTITLED1_LIST_H
#include "moves.h"

struct s_node;
typedef struct s_node t_node;

typedef struct s_cell_move
{
    t_move value;
    struct s_cell_move * next;
} t_cell_move;

typedef struct s_list_move{
    t_cell_move * head;
}t_list_move;

typedef struct s_cell_son{
    t_node* curr_node;
    struct s_cell_son * next;
}t_cell_son;

typedef struct s_list_son
{
    t_cell_son* head;
}t_list_son;

#endif //UNTITLED1_LIST_H
