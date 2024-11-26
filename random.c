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

int random_i_j(int i, int j)
{
    srand(time(NULL)+i+15*j+17*i*j);
    return rand();
}


t_localisation random_position_orientation(t_map map){
    int pos_x = (num_random_time()+1201)%map.x_max;
    int pos_y = (num_random_time()+647)%map.y_max;
    int i = 3;
    int j = 2;
    while (map.soils[pos_y][pos_x] == 4 || map.soils[pos_y][pos_x]==0){
        pos_x = (random_i_j(j,i)+1201)%map.x_max;
        pos_y = ((random_i_j(i,j)+647))%map.y_max;
        i = j*7+3;
        j = i*3+1;
    }
    int orientation = num_random_time()%4;
    t_orientation ori = orientation;
    t_localisation loc = loc_init(pos_x,pos_y,ori);
    return loc;
}
