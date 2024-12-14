#ifndef LOOP_LIST
#define LOOP_LIST
#include "../utilities/delegate.h"

typedef struct loop_list_s{
    struct loop_list_s* prev;
    struct loop_list_s* next;

    void *value;
}loop_list_t;

loop_list_t* new_loop_list(void *value);

void push_start(void *value);
void push_back(void *value);

loop_list_t* pop_last();
loop_list_t* pop_first();

void for_each_in_loop_list(loop_list_t *list, ACTION(func, (loop_list_t *member)));

void free_loop_list();

#endif
