#include <stdio.h>
#include "map.h"
#include "list.h"
#include "loc.h"
#include "tree.h"
#include "random.h"
#include "select_move.h"

int main() {
    t_map example_map, actual_map, training_map;
    int running = 1;
    int choice, nb_move, phase, move_by_phase;
    t_list_move * liste_move, * move_since_beg, * move_phase;
    t_localisation loc;
    t_tree * tree;
    t_node * min_node;
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
                printf("Combien de  mouvement possible par phase ?\n");
                scanf(" %d", &nb_move);
                phase = 0;
                move_by_phase = 5;
                move_since_beg = create_empty_list_move();
                loc = random_position_orientation(actual_map.x_max, actual_map.y_max);
                while (robot_in_base(loc, actual_map) == 0){
                    liste_move = set_list_move(create_t_list_init(), nb_move);
                    tree = creating_tree(liste_move, move_by_phase, loc, actual_map);
                    min_node = find_min_node_tree(*tree);
                    move_phase = recover_move_node(min_node);
                    move_by_phase = 5;
                    if (passed_by_reg(min_node))
                        move_by_phase = 4;
                    concatenate_list_move(move_since_beg, move_phase);
                    loc = min_node->loc;
                    phase ++;
                }
                printf("déplacement finaux après %d phase:\n", phase);
                affichage_t_list_move(move_since_beg);
                del_list_move(move_since_beg);
                del_list_move(move_phase);
                del_tree(tree);
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

    return 0;
}
