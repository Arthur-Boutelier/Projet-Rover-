#include <stdio.h>
#include "map.h"
#include "select_move.h"
#include "tree.h"
#include "random.h"
#include <fcntl.h>
#include <unistd.h>

int main() {
    t_map map;
    // The following preprocessor directive checks if the code is being compiled on a Windows system.
    // If either _WIN32 or _WIN64 is defined, it means we are on a Windows platform.
    // On Windows, file paths use backslashes (\), hence we use the appropriate file path for Windows.
    #if defined(_WIN32) || defined(_WIN64)
        map = createMapFromFile("..\\maps\\example1.map");
    #else
        map = createMapFromFile("../maps/example1.map");
    #endif
    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n");
    }
    // printf the costs, aligned left 5 digits
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }
    displayMap(map);
    
    t_list_freemove* liste_freemove = create_t_list_init();
    t_list_move* liste_move = set_list_move(liste_freemove);
    affichage_t_list_freemove(liste_freemove);
    affichage_t_list_move(liste_move);
    //t_tree * tree = creating_tree();
    int* liste_gngngn = create_list_random(13,7 );
    for(int i = 0; i < 91; i++){
        printf("%d\n",liste_gngngn[i]);
    }
    int** matrix = fill_matrix(13, 7, liste_gngngn);
    add_base_station(matrix, 13, 7);
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;

}
