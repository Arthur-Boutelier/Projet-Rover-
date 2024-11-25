
#ifndef RANDOM_H
#define RANDOM_H
#include "loc.h"
#include "map.h"
/**
 * @brief Fonction qui renvoie un random à partir du temps de l'ordinateur
 * @return int nombre random
 */
int num_random_time();

/**
 * @brief fonction qui renvoie un int random à partir de 2 int, utile pour random dans des boucles
 * @param int i : int parametre à random
 * @param int j : int parametre à random
 * @return int nombre random
 */
int random_i_j(int i, int j);

/**
 * @brief fonction qui sert à positionner le robot aléatoirement au début
 * @param t_map map : type t_map, map où il faut calculer la position du robot initiale
 * @return t_localisation localistation du robot
 */
t_localisation random_position_orientation(t_map map);



#endif //RANDOM_H
