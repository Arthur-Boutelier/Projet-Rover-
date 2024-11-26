#ifndef UNTITLED1_LIST_H
#define UNTITLED1_LIST_H
#include "moves.h"


struct s_node;
typedef struct s_node t_node;

/**
 * @brief Structure d'un d'une cellule de la liste de mouvement
 */
typedef struct s_cell_move
{
    t_move value;
    struct s_cell_move *next;
} t_cell_move;

/**
 * @brief Structure d'une liste de mouvement
 */
typedef struct s_list_move{
    t_cell_move * head;
}t_list_move;

/**
 * @brief Structure d'une cellule de la liste de fils
 */
typedef struct s_cell_son{
    t_node* node;
    struct s_cell_son *next;
}t_cell_son;

/**
 * @brief Structure d'une liste de fils
 */
typedef struct s_list_son
{
    t_cell_son* head;
}t_list_son;

/**
 * @brief Fonction pour créer une cellule de la liste de mouvement
 * @param val : valeur de la cellule
 * @return t_cell_move* : la cellule
 */
t_cell_move *create_cell_move(t_move val);

/**
 * @brief Fonction pour créer une cellule de la liste de fils
 * @param val : valeur de la cellule
 * @return t_cell_son* : la cellule
 */
t_cell_son *create_cell_son(t_node* val);

/**
 * @brief Fonction pour ajouter une cellule en tête de la liste de mouvement
 * @param list : liste
 * @param val : valeur de la cellule
 * @return none
 */
void addHead_cell_move(t_list_move *list, t_move val);

/**
 * @brief Fonction pour ajouter une cellule en tête de la liste de fils
 * @param list : liste
 * @param val : valeur de la cellule
 * @return none
 */
void addHead_cell_son(t_list_son *list, t_node* val);

/**
 * @brief Fonction pour créer une liste de mouvement vide
 * @return t_list_move* : liste vide
 */
t_list_move* create_empty_list_move();

/**
 * @brief Fonction pour créer une liste de fils vide
 * @return t_list_son* : liste vide
 */
t_list_son* create_empty_list_son();

/**
 * @brief Fonction pour supprime une valeur de la liste de mouvement
 * @param list : liste
 * @param val : valeur à supprimer
 * @return t_list_move* : liste sans la valeur
 */
t_list_move* removeVal_move(t_list_move *list, t_move val);

/**
 * @brief Structure d'une cellule d'une liste de mouvement avec probabilité
 */
typedef struct s_cell_freemove
{
    t_move value;
    int numberofmoveleft;
    struct s_cell_freemove * next;
}t_cell_freemove;

/**
 * @brief Structure d'une liste de mouvement avec probabilité
 */
typedef struct s_list_freemove{
    t_cell_freemove * head;
}t_list_freemove;

/**
 * @brief fonction qui créer une cellule de la liste de mouvement avec probabilité
 * @param val : valeur de la cellule
 * @param nb : nombre de fois où la cellule peut être utilisé
 * @return
 */
t_cell_freemove *create_cell_freemove(t_move val,int nb);

/**
 * @brief fonction qui ajoute une cellule en tête de la liste de mouvement avec probabilité
 * @param list : liste
 * @param val : valeur de la cellule
 * @param nb : nombre de fois où la cellule peut être utilisé
 * @return none
 */
void addHead_cell_freemove(t_list_freemove *list, t_move val, int nb);

/**
 * @brief fonction qui créer une liste de mouvement avec probabilité vide
 * @return t_list_freemove* : liste vide
 */
t_list_freemove* create_empty_list_freemove();

/**
 * @brief fonction qui affiche la liste de mouvement avec probabilité
 * @param list : liste
 * @return none
 */
void affichage_t_list_freemove(t_list_freemove* list);

/**
 * @brief fonction qui affiche la liste de mouvement
 * @param list : liste
 * @return none
 */
void affichage_t_list_move(t_list_move* list);

/**
 * @brief fonction qui supprime une valeur de la liste de fils
 * @param list : liste de fils
 * @return none
 */
void del_list_son(t_list_son * list_son);

/**
 * @brief fonction qui supprime la liste de mouvement
 * @param list_move : liste de mouvement
 * @return none
 */
void del_list_move(t_list_move * list_move);

/**
 * @brief fonction rassemble 2 listes de mouvement
 * @param list_1 : liste 1
 * @param list_2 : liste 2
 * @return none
 */
void concatenate_list_move(t_list_move * list_1, t_list_move * list_2);
#endif //UNTITLED1_LIST_H
