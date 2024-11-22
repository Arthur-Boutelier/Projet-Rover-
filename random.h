#include "loc.h"
#include "map.h"

int num_random_time();
t_localisation random_position_orientation(int taille_m_x, int taille_m_y);
int* create_list_random(int rows, int cols);
int** fill_matrix(int x, int y, int* list_proba);
void add_base_station(int** matrix, int taille_m_x, int taille_m_y);
#ifndef RANDOM_H
#define RANDOM_H

#endif //RANDOM_H
