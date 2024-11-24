#include <stdio.h>
#include "map.h"
#include "select_move.h"
#include "tree.h"
#include "loc.h"
#include "random.h"

int main() {
    t_map example_map, actual_map, training_map;
    int running = 0;
    int choice;
    // The following preprocessor directive checks if the code is being compiled on a Windows system.
    // If either _WIN32 or _WIN64 is defined, it means we are on a Windows platform.
    // On Windows, file paths use backslashes (\), hence we use the appropriate file path for Windows.
    #if defined(_WIN32) || defined(_WIN64)
        example_map = createMapFromFile("..\\maps\\example1.map");
        training_map = createMapFromFile("..\\maps\\training.map");
    #else
        example_map = createMapFromFile("../maps/example1.map");
        training_map = createMapFromFile("../maps/training.map");
    #endif

    actual_map = example_map;
    while (running){
        printf("What do you want to do :\n");
        printf("1 : Try the rover\n");
        printf("2 : Display map\n");
        printf("3 : Display map cost\n");
        printf("4 : Display soil\n");
        printf("5 : Change map\n");
        printf("6 : Exit\n");
        do{
            scanf(" %d", &choice);
        } while (choice > 6 || choice < 0);
        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                display_soil(actual_map);
                break;
            case 5:
                break;
            case 6:
                running = 0;
                break;
            default:
                break;
        }

    }
    t_localisation initial_pos = loc_init(5,0, 3);
    t_list_freemove* liste_freemove = create_t_list_init();
    t_list_move* liste_move = set_list_move(liste_freemove, 15);
    t_tree * tree = creating_tree(liste_move, 5, initial_pos, actual_map);
    t_node * min_node = find_min_node_tree(*tree);
    t_list_move* liste_reco_move = recover_move_node(min_node);
    affichage_t_list_move(liste_reco_move);

    return 0;
}
