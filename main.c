#include <stdio.h>
#include "map.h"
#include "list.h"
#include "loc.h"
#include "tree.h"
#include "random.h"
#include "select_move.h"
#include "counter.h"

int main() {
    t_counter * counter_tot = create_counter();
    t_counter * counter_tree_creation = create_counter();
    t_counter * counter_min = create_counter();
    t_counter * counter_path = create_counter();
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
    start_counter(counter_tot);
    while (running){
        printf("What do you want to do :\n");
        printf("1 : Try the rover\n");
        printf("2 : Display map\n");
        printf("3 : Display map cost\n");
        printf("4 : Display soil\n");
        printf("5 : Change map\n");
        printf("6 : Exit\n");
        do{
            scanf("%d", &choice);
        } while (choice > 6 || choice < 0);
        switch (choice) {
            case 1:
                printf("\nBetween how many move the rover can choose ?\n");
                scanf("%d", &nb_move);
                phase = 0;
                move_by_phase = 5;
                move_since_beg = create_empty_list_move();
                loc = random_position_orientation(actual_map);
                printf("\nEmplacement de depart : %d %d %d\n", loc.pos.x, loc.pos.y, loc.ori);
                while (robot_in_base(loc, actual_map) == 0){
                    phase ++;
                    liste_move = set_list_move(create_t_list_init(), nb_move, phase);
                    start_counter(counter_tree_creation);
                    tree = creating_tree(liste_move, move_by_phase, loc, actual_map);
                    stop_counter(counter_tree_creation);
                    start_counter(counter_min);
                    min_node = find_min_node_tree(*tree);
                    stop_counter(counter_min);
                    start_counter(counter_path);
                    move_phase = recover_move_node(min_node);
                    stop_counter(counter_path);
                    move_by_phase = 5;
                    if (passed_by_reg(min_node))
                        move_by_phase = 4;
                    concatenate_list_move(move_since_beg, move_phase);
                    loc = min_node->loc;
                    printf("\nPhase %d :\n", phase);
                    printf("Time for building tree : %d microseconds \n", display_counter(*counter_tree_creation));
                    printf("Time to find the minimum node : %d microseconds \n", display_counter(*counter_min));
                    printf("Time to find the path to the minumum node : %d microseconds\n", display_counter(*counter_path));
                }
                printf("\nDeplacement finaux apres %d phase:\n", phase);
                affichage_t_list_move(move_since_beg);
                del_list_move(move_since_beg);
                del_tree(tree);
                printf("\n\n");
                break;
            case 2:
                printf("\n\n");
                displayMap(actual_map);
                printf("\n\n");
                break;
            case 3:
                printf("\n\n");
                display_cost(actual_map);
                printf("\n\n");
                break;
            case 4:
                printf("\n\n");
                display_soil(actual_map);
                printf("\n\n");
                break;
            case 5:
                printf("\n\nWhat type of map do you want ?\n");
                printf("1 : Example map\n");
                printf("2 : Training map\n");
                printf("3 : Random map\n");
                do {
                    scanf("%d", &choice);
                } while (choice < 1 || choice > 3);
                switch(choice){
                    case 1:
                        actual_map = example_map;
                        break;
                    case 2:
                        actual_map = training_map;
                        break;
                    case 3:
                        printf("What size do you want ? (x,y)\n");
                        int x, y;
                        do {
                            scanf("%d,%d", &x, &y);
                        } while (x<1 || y<1);
                        actual_map = create_random_Map(x,y);
                        break;
                }
                break;
            case 6:
                running = 0;
                break;
            default:
                break;
        }

    }
    printf("Temp total utilise : %.4f seconde", (float)display_counter(*counter_tot)/1000000);
    return 0;

}
