#include "list.h"
#include<math.h>
#include "../utilities/delegate.h"

list_t* new_list(){
    list_t* self = malloc(sizeof(list_t));
    self->prev = nullptr;
    return self;
}

list_t* new_list_with(node_t* first){
    list_t* self = new_list();
    self->prev = first;

    return self;
}

int count_of_list_elements(const list_t* self){
    node_t* current = self->prev;
    int count = 0;

    while (current != nullptr){
        count++;
        current = current->Next;
    }
    return count;
}

void add_to_list(list_t* self, void* value){
    if (self->prev == nullptr){
        self->prev = new_node(value);
        return;
    }
    node_t* current = self->prev;

    while (current != nullptr){
        if (current->Next == nullptr)
            break;
        current = current->Next;
    }
    current->Next = new_node(value);
}

void* remove_from_list(const list_t* self, int index){
    node_t* last;
    node_t* current = self->prev;

    if (index > count_of_list_elements(self))
        return nullptr;

    while (index != 0){
        index--;
        last = current;
        current = current->Next;
    }
    last->Next = current->Next;

    return current;
}

node_t* clear_list(list_t* self, bool free_nodes){
    if (free_nodes)
        free_this_node(self->prev, free_nodes);

    node_t* nodes = self->prev;
    self->prev = nullptr;

    return nodes;
}

void* get_list_value(const list_t* self, int index){
    node_t* current = self->prev;


    if (index > count_of_list_elements(self))
        return nullptr;

    while (index != 0){
        index--;
        current = current->Next;
    }
    return current->Value;
}

void set_list_value(const list_t* self, unsigned long index, void* value){
    node_t* last;
    node_t* current = self->prev;

    if (index > count_of_list_elements(self))
        return;

    while (index != 0){
        index--;
        last = current;
        current = current->Next;
    }

    current->Value = value;
}

double min_of_list(const list_t* self, FUNC(minFunc, double, (const void*))){
    if (self->prev == nullptr)
        return 0;

    node_t* current = self->prev;
    node_t* next = current->Next;
    double min_value = minFunc(current->Value);

    while (next != nullptr){
        min_value = fmin(minFunc(current->Value), minFunc(next->Value));
        current = next;
        next = next->Next;
    }
    return min_value;
}

double max_of_list(const list_t* self, FUNC(maxFunc, double, (const void*))){
    if (self->prev == nullptr)
        return 0;

    node_t* current = self->prev;
    node_t* next = current->Next;
    double max_value = maxFunc(current->Value);

    while (next != nullptr){
        max_value = fmax(maxFunc(current->Value), maxFunc(next->Value));
        current = next;
        next = next->Next;
    }
    return max_value;
}

void for_each_list_element(const list_t* self, FUNC(func, void, (const void *))){
    node_t* current = self->prev;

    while (current != nullptr){
        func(current->Value);
        current = current->Next;
    }
}

node_t* free_list(list_t* self, bool freeAllNodes){
    if (freeAllNodes)
        free_this_node(self->prev, freeAllNodes);
    node_t* nodes = self->prev;
    free(self);
    return nodes;
}