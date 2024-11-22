//
// Created by proff on 22/11/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include <time.h>
#include "loc.h"
#include <unistd.h>
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



int** fill_matrix(int x, int y, int* list_proba){
    int** matrix = (int**)malloc(x * sizeof(int*));
    for (int i = 0; i < x; i++) {
        matrix[i] = (int*)malloc(y * sizeof(int));
    }
    int cmpt = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            matrix[i][j] = list_proba[cmpt++];
        }
    }
    return matrix;
}

int* create_list_random(int rows, int cols) {
    int* list_proba = (int*)malloc(rows*cols*sizeof(int));
    int list_probabilite[10] = {1,1,1,1,1,2,2,3,3,4};
    for (int i = 0; i < rows*cols; i++) {
        printf("%d\n",i);
        sleep(1);
        int pick_random = list_probabilite[num_random_time()%10];
        list_proba[i] = pick_random;
    }
    return list_proba;
}

void add_base_station(int** matrix, int taille_m_x, int taille_m_y){
    int pos_x = ((num_random_time()%65)*6735)%taille_m_x;
    int pos_y = ((num_random_time()%87)*9713)%taille_m_y;
    matrix[pos_x][pos_y] = 0;
}