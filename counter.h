#ifndef UNTITLED1_COUNTER_H
#define UNTITLED1_COUNTER_H
#include <sys/time.h>

typedef struct timeval t_timeval;
typedef enum e_state{
    unitialized,
    running,
    stopped
}t_state;

typedef struct s_counter{
    t_timeval beg;
    t_timeval end;
    t_state state;
}t_counter;

t_counter * create_counter();
void start_counter(t_counter * counter);
void stop_counter(t_counter * counter);
int display_counter(t_counter counter);

#endif //UNTITLED1_COUNTER_H
