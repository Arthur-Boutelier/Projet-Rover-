#ifndef UNTITLED1_SELECT_MOVE_H
#define UNTITLED1_SELECT_MOVE_H
#include "list.h"
#include "random.h"
#include "moves.h"

/**
 * @brief fonction qui donne une list contenant les différents mouvepents possibles ainsi que leur proba
 * @return t_list_freemove* : liste contenant les mouvements et probabilité associées
 */
t_list_freemove* create_t_list_init();

/**
 * @brief fonction qui choisis les mouvements aléatoirement en fonction de la liste avec les probabilitées
 * @param t_list_freemove* list : liste des proba associées aux mouvements
 * @param int nb : nombre de mouvements désirés
 * @return t_list_move* list avec les mouvements choisis
 */
t_list_move* set_list_move(t_list_freemove* list, int nb);

#endif //UNTITLED1_SELECT_MOVE_H
