#include "counter.h"
#include <stdlib.h>

t_counter * create_counter(){
    t_counter * counter = (t_counter*) malloc(sizeof(t_counter));
    counter->state = unitialized;
    return counter;
}

void start_counter(t_counter * counter){
    gettimeofday(&counter->beg, NULL);
    counter->state = running;
}

void stop_counter(t_counter * counter){
    switch (counter->state) {
        case unitialized:
            gettimeofday(&counter->beg, NULL);
            gettimeofday(&counter->end, NULL);
            counter->state = stopped;
            break;
        case running:
            gettimeofday(&counter->end, NULL);
            counter->state = stopped;
            break;
        case stopped:
            break;

    }
}
int display_counter(t_counter counter){
    t_timeval time;
    switch (counter.state){
        case unitialized:
            return -1;
        case running:
            gettimeofday(&time, NULL);
            return time.tv_sec * 1000000 + time.tv_usec - counter.beg.tv_sec * 1000000 - counter.beg.tv_usec;
        case stopped:
            return counter.end.tv_sec * 1000000 + counter.end.tv_usec - counter.beg.tv_sec * 1000000 - counter.beg.tv_usec;
    }
};