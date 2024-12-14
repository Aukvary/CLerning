#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef struct node{
    struct node* Next;
    void* Value;
}node_t;

node_t* new_node(void* value){
    node_t* node = malloc(sizeof(node_t));

    node->Value = value;
    node->Next = nullptr;

    return node;
}

node_t* new_node_with(void* value, node_t* childNode){
    node_t* node = new_node(value);
    node->Next = childNode;

    return node;
}

node_t* free_this_node(node_t* self, bool free_all){
    if (free_all){
        node_t* current = self;
        node_t* next;
        while (current != nullptr){
            next = current->Next;
            free(current);
            current = next;
        }
        return nullptr;
    } else{
        node_t* return_value = self->Next;
        free(self);
        return return_value;
    }
}
#endif



