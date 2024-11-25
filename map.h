#ifndef UNTITLED1_MAP_H
#define UNTITLED1_MAP_H
#include "loc.h"
#include "queue.h"

#define COST_UNDEF 65535
/**
 * @brief Enum for the possible soils of the map
 */

struct s_node;
typedef struct s_node t_node;

typedef enum e_soil
{
    BASE_STATION,
    PLAIN,
    ERG,
    REG,
    CREVASSE
} t_soil;

/**
 * @brief Array of costs for the soils
 */
static const int _soil_cost[5] = {0, 1, 2, 4, 10000};

/**
 * @brief Structure for the map

 */
typedef struct s_map
{
    t_soil  **soils;
    int     **costs;
    int     x_max;
    int     y_max;
} t_map;

/**
 * @brief Function to initialise the map from a file
 * @param filename : the name of the file
 * @return the map
 */
t_map createMapFromFile(char *);

/**
 * @brief Function to create a standard training map (11x11 with only plains and base station in the middle)
 * @param none
 * @return a standard map
 */
 t_map createTrainingMap();

/**
 * @brief display the map with characters
 * @param map : the map to display
 */
void displayMap(t_map);

/**
 * @brief Fonction qui pose la base station sur une map donné
 * @param t_map map : map où il faut rajouter la base station
 */
void add_base_station(t_map* map);

/**
 * @brief fonction qui créer une nouvelle map à partir de la taille de la matrice souhaité
 * @param int x : taille x de la matrice
 * @param int y : taille y de la matrice
 * @return t_map map avec les coefficients qui correponds aux différentes case.
 */


t_map create_random_Map(int x,int y);
void display_cost(t_map map);
void display_soil(t_map map);
int robot_in_base(t_localisation loc, t_map map);
int passed_by_reg(t_node* final_node);

#endif //UNTITLED1_MAP_H
