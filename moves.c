#include "moves.h"
#include <stdlib.h>
#include "list.h"
#include <stdio.h>
/* prototypes of local functions */
/* local functions are used only in this file, as helper functions */

/**
 * @brief Function to rotate the robot according to a move and its actual orientation
 * @param ori : the actual orientation of the robot
 * @param move : the move to do
 * @return the new orientation of the robot
 */
t_orientation rotate(t_orientation, t_move );

/**
 * @brief function to translate the robot according to a move and its actual position
 * @param loc : the actual localisation of the robot
 * @param move : the move to do
 * @return the new localisation of the robot
 */
t_localisation translate(t_localisation , t_move);

/* definition of local functions */

t_orientation rotate(t_orientation ori, t_move move)
{
    int rst = 0;
    switch (move)
    {
        case T_LEFT:
            rst=3;
            break;
        case T_RIGHT:
            rst=1;
            break;
        case U_TURN:
            rst=2;
            break;
        default:
            break;
    }
    return (ori+rst)%4;
}

t_localisation translate(t_localisation loc, t_move move)
{
    /** rules for coordinates:
     *  - x grows to the right with step of +1
     *  - y grows to the bottom with step of +1
     *  - the origin (x=0, y=0) is at the top left corner
     */
    t_position res = loc.pos;
    switch (move) {
        case F_10:
            switch (loc.ori) {
                case NORTH:
                    res.y = loc.pos.y - 1;
                    break;
                case EAST:
                    res.x = loc.pos.x + 1;
                    break;
                case SOUTH:
                    res.y = loc.pos.y + 1;
                    break;
                case WEST:
                    res.x = loc.pos.x - 1;
                    break;
                default:
                    break;
            }
            break;
        case F_20:
            switch (loc.ori) {
                case NORTH:
                    res.y = loc.pos.y - 2;
                    break;
                case EAST:
                    res.x = loc.pos.x + 2;
                    break;
                case SOUTH:
                    res.y = loc.pos.y + 2;
                    break;
                case WEST:
                    res.x = loc.pos.x - 2;
                    break;
                default:
                    break;
            }
            break;
        case F_30:
            switch (loc.ori) {
                case NORTH:
                    res.y = loc.pos.y - 3;
                    break;
                case EAST:
                    res.x = loc.pos.x + 3;
                    break;
                case SOUTH:
                    res.y = loc.pos.y + 3;
                    break;
                case WEST:
                    res.x = loc.pos.x - 3;
                    break;
                default:
                    break;
            }
            break;
        case B_10:
            switch (loc.ori) {
                case NORTH:
                    res.y = loc.pos.y + 1;
                    break;
                case EAST:
                    res.x = loc.pos.x - 1;
                    break;
                case SOUTH:
                    res.y = loc.pos.y - 1;
                    break;
                case WEST:
                    res.x = loc.pos.x + 1;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    return loc_init(res.x, res.y, loc.ori);

}

/* definitions of exported functions */

char *getMoveAsString(t_move move)
{
    return _moves[move];
}

t_localisation move(t_localisation loc, t_move move)
{
    t_localisation new_loc = translate(loc, move);
    new_loc.ori = rotate(loc.ori, move);
    return new_loc;
}

void updateLocalisation(t_localisation *p_loc, t_move m)
{
    *p_loc = move(*p_loc, m);
}

t_move update_move_soil(t_move move, t_soil soil){
    if (soil == ERG){
        switch (move) {
            case U_TURN:
                return T_LEFT;
            case F_10:
                return STILL;
            case F_20:
                return F_10;
            case F_30:
                return F_20;
            default:
                return STILL;
        }
    }
    else
        return move;
}

t_list_move * intermediate_move(t_move move){
    t_list_move * inter_move = create_empty_list_move();
    if (move > F_20)
        addHead_cell_move(inter_move, F_20);
    addHead_cell_move(inter_move, F_10);
    return inter_move;
}

int not_passing_crevasse(t_move curr_move, t_map map, t_localisation loc){
    if(curr_move == F_20 || curr_move == F_30){
        t_list_move * inter_move = intermediate_move(curr_move);
        t_cell_move * curr = inter_move->head;
        while (curr != NULL){
            t_localisation new_loc = move(loc, curr->value);
            if (isValidLocalisation(new_loc.pos, map.x_max, map.y_max)){
                if (map.soils[new_loc.pos.y][new_loc.pos.x] == CREVASSE) {
                    return 0;
                }
            }
            curr = curr->next;
        }
    }
    return 1;
}