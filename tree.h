
#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H
#include "moves.h"
#include "list.h"
#include "loc.h"
#include "map.h"

/**
 * @brief Structure d'un noeud
 */
typedef struct s_node{
    int value;
    t_move move;
    t_list_move * available_move;
    t_list_son * son;
    t_localisation loc;
    t_map map;
    t_node * parent;
} t_node;

/**
 * @brief Structure d'un arbre
 */
typedef struct s_tree
{
    t_node* root;
} t_tree;

/**
 * @brief Créer un arbre vide
 * @return t_tree* arbre vide
 */
t_tree * create_empty_tree();

/**
 * @brief creer un noeud vide
 * @return t_node* noeuds vide
 */
t_node * create_empty_node();

/**
 * @brief remplir un noeud
 * @param available_move : mouvement en question
 * @param node : noeud
 * @param value : valeur du noeud
 * @param map : map où on se trouve
 * @return noeud rempli
 */
void fill_node(t_node * node, int value, t_move move, t_list_move* available_move, t_localisation loc, t_map map);

/**
 * @brief creer un arbre à partir d'un mouvement
 * @param available_move : mouvement en question
 * @param depht : profondeur
 * @param initial_position : position inital
 * @param map : map où on se trouve
 * @return t_tree* arbre créer
 */
t_tree * creating_tree(t_list_move * available_move, int depht, t_localisation initial_position, t_map map);

/**
 * @brief Fonction appellé dan creating_tree pour effectuer le récursif
 * @param node : noeud
 * @param depht : profondeur du noeud
 */
void creating_tree_node(t_node * node, int depht);

/**
 * @brief Fonction qui permet de trouver le mouvement idéal
 * @param loc : localisation du robot
 * @param available_move : liste contenant les mouvements possibles
 * @param map : map dans lequel on se trouve
 * @return t_list_move
 */
t_list_move * find_optimal_move(t_localisation loc, t_list_move * available_move, t_map map);

/**
 * @brief Fonction qui creer le noeud fils à partir d'un mouvement
 * @param curr_node : noeud actuel
 * @param new_loc : nouelle location du robot après mouvement
 * @param new_list_move : nouvelle list de mouvement après le mouvement
 * @param curr_move : mouvement actuel
 * @return le nouveau noeud
 */
t_node * create_node_son(t_node * curr_node, t_localisation new_loc, t_list_move * new_list_move, t_move curr_move);

/**
 * @brief Fonction qui sert à trouver le minimum d'un arbre
 * @param tree : arbre où il faut retrouver le minimum
 * @return t_node* du noeud le plus petit
 */
t_node * find_min_node_tree(t_tree tree);

/**
 * @brief Fonction qui est utilisé dans le récursif de find_min_node_tree
 * @param node : noeud
 * @return t_node*
 */
t_node * find_min_node(t_node * node);

/**
 * @brief Fonction qui sert à retrouver le chemin jusqu'à ce noeud
 * @param node : noeud
 * @return retroune une liste de mouvement
 */
t_list_move * recover_move_node(t_node * node);

/**
 * @brief fonction qui calcule la profondeur d'un noeud sur un arbre
 * @param node : noeud à analyser
 * @return int qui correspond à la profondeur du noeud
 */
int depth_node(t_node* node);

/**
 * @brief fonction qui supprime un arbre
 * @param tree : arbre
 */
void del_tree(t_tree* tree);
#endif //UNTITLED1_TREE_H
