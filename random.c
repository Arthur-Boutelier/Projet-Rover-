//
// Created by proff on 22/11/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include <time.h>

int num_random_time()
{
    srand(time(NULL));
    return rand();
}

t_localisation random_position_orientation(int taille_m_x, int taille_m_y){
    int pos_x = ((num_random_time()%29)*348)%taille_m_x;
    int pos_y = ((num_random_time()%37)*427)%taille_m_y;
    int orientation = num_random_time()%3;
    t_orientation ori = orientation;
    t_localisation loc = loc_init(pos_x,pos_y,ori);
    return loc;
}

