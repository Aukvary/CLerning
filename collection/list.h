#ifndef COLLECTION_H
#define COLLECTION_H

#include "nodes.h"

typedef struct list_s{
    struct list_s *prev;
    struct list_s *next;
}list_t;


list_t* new_list();

list_t* new_list_with(node_t* first);

int count_of_list_elements(const list_t* self);

void add_to_list(list_t* self, void* value);

void* remove_from_list(const list_t* self, int index);

node_t* clear_list(list_t* self, bool free_nodes);

void* get_list_value(const list_t* self, int index);

void set_list_value(const list_t* self, unsigned long index, void* value);

double min_of_list(const list_t* self, double(*minFunc)(const void*));

double max_of_list(const list_t* self, double(*maxFunc)(const void*));

void for_each_list_element(const list_t* self, void(*func)(const void*));

node_t* free_list(list_t* self, bool freeAllNodes);
#endif