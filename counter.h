#ifndef UNTITLED1_COUNTER_H
#define UNTITLED1_COUNTER_H
#include <sys/time.h>
/**
 * @brief type d'un timeval de la lybrary sys/time.h
 */
typedef struct timeval t_timeval;

/**
 * @brief enum du type state d'un counter
 */
typedef enum e_state{
    unitialized,
    running,
    stopped
}t_state;

/**
 * @brief structure d'un counter
 */
typedef struct s_counter{
    t_timeval beg;
    t_timeval end;
    t_state state;
}t_counter;

/**
 * @brief fonction qui crée un counteur
 * @return t_counteur * : counter créé
 */
t_counter * create_counter();

/**
 * @brief fonction qui démarre le compteur
 * @param t_counter * counteur : counteur à lancé
 */
void start_counter(t_counter * counter);

/**
 * @brief fonction qui stop le compteur
 * @param t_counteur * counter : counteur à stopper
 */
void stop_counter(t_counter * counter);

/**
 * @brief fonction renvoie le temp entre le début et la fin d'un counter en microseconde
 * @param t_counter counter : counter à afficher
 * @return int : valeur en millisecond
 */
int display_counter(t_counter counter);

#endif //UNTITLED1_COUNTER_H
