#ifndef UNTITLED1_LIST_H
#define UNTITLED1_LIST_H
#include "tree.h"
#include "moves.h"

typedef struct s_cell_move
{
    t_move value;
    struct s_cell_move * next;
} t_cell_move;

typedef struct s_list_move{
    t_cell_move * head;
}t_list_move;

#endif //UNTITLED1_LIST_H