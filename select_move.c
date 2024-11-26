#include "select_move.h"
#include <stdio.h>


t_list_freemove* create_t_list_init()
{
  t_list_freemove* list_init = create_empty_list_freemove();
  addHead_cell_freemove(list_init, U_TURN, 7);
  addHead_cell_freemove(list_init, T_RIGHT, 21);
  addHead_cell_freemove(list_init, T_LEFT, 21);
  addHead_cell_freemove(list_init, B_10, 7);
  addHead_cell_freemove(list_init, F_30, 7);
  addHead_cell_freemove(list_init, F_20, 15);
  addHead_cell_freemove(list_init, F_10, 22);
  return list_init;
}

t_list_move* set_list_move(t_list_freemove* list, int nb, int phase){
  t_list_move* list_move = create_empty_list_move();
  t_cell_freemove* current;
  for (int i=0; i<nb; i++){
    int number_random = random_i_j(i + (phase+4)*5, (i+48)*2)%(100-i)+1;
    current = list->head;
    while(current->numberofmoveleft < number_random){
        number_random = number_random - current->numberofmoveleft;
        current = current->next;
    }
    addHead_cell_move(list_move, current->value);
    current->numberofmoveleft = current->numberofmoveleft - 1;
  }
  return list_move;
}