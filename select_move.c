#include "select_move.h"
#include "list.h"



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








