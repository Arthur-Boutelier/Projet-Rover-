#ifndef UNTITLED1_LIST_H
#define UNTITLED1_LIST_H
#include "moves.h"


struct s_node;
typedef struct s_node t_node;


typedef struct s_cell_move
{
    t_move value;
    struct s_cell_move *next;
} t_cell_move;

typedef struct s_list_move{
    t_cell_move * head;
}t_list_move;

typedef struct s_cell_son{
    t_node* node;
    struct s_cell_son *next;
}t_cell_son;

typedef struct s_list_son
{
    t_cell_son* head;
}t_list_son;

t_cell_move *create_cell_move(t_move val);
t_cell_son *create_cell_son(t_node* val);

void addHead_cell_move(t_list_move *list, t_move val);
void addHead_cell_son(t_list_son *list, t_node* val);

t_list_move* create_empty_list_move();
t_list_son* create_empty_list_son();

t_list_move* removeVal_move(t_list_move *list, t_move val);

typedef struct s_cell_freemove
{
    t_move value;
    int numberofmoveleft;
    struct s_cell_freemove * next;
}t_cell_freemove;

typedef struct s_list_freemove{
    t_cell_freemove * head;
}t_list_freemove;

t_cell_freemove *create_cell_freemove(t_move val,int nb);

void addHead_cell_freemove(t_list_freemove *list, t_move val, int nb);

t_list_freemove* create_empty_list_freemove();

void affichage_t_list_freemove(t_list_freemove* list);
void affichage_t_list_move(t_list_move* list);
void del_list_son(t_list_son * list_son);
void del_list_move(t_list_move * list_move);
void concatenate_list_move(t_list_move * list_1, t_list_move * list_2);
#endif //UNTITLED1_LIST_H
