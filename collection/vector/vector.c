#include "vector.h"
#include <stdio.h>

vector_t *new_vector(size_t member_size, size_t capacity){
    vector_t *self = malloc(sizeof(vector_t));

    self->__len__ = vector_len;

    self->__iterator__.start = vector_iterator_start;
    self->__iterator__.next = vector_iterator_next;
    self->__iterator__.end = vector_iterator_end;

    self->__capacity__ = capacity;
    self->__member_size__ = member_size;
    self->__member_count__ = 0;

    if (capacity) {
        self->__start__ = calloc(capacity, member_size);
        self->__end__ = self->__start__ + capacity * member_size;
    }


    return self;
}

size_t vector_len(vector_t* self){
    return self->__member_count__;
}


void vector_iterator_start(void *self){
    ((vector_t *)self)->__current_iterator_member_index__ = 0;
}

void *vector_iterator_next(void *self){
    vector_t *vec = (vector_t *)self;

    void *result = vec->__start__ + vec->__current_iterator_member_index__ * vec->__member_size__;

    vec->__current_iterator_member_index__++;
    return result;
}

bool vector_iterator_end(void *self){
    vector_t *vec = (vector_t *)self;
    return vec->__current_iterator_member_index__ > vec->__member_count__;
}

bool vector_extend(vector_t *self){
    if (self->__capacity__ == 0){
        self->__start__ = malloc(self->__member_size__);
        self->__end__ = self->__start__ + self->__member_size__;
        bool good = self->__start__ != nullptr;
        if (good)
            self->__capacity__ = 1;
        return good;
    }
    void *temp = self->__start__;
    self->__start__ = realloc(self->__start__, self->__capacity__ * 2);
    if (self->__start__) {
        self->__capacity__ *= 2;
        self->__end__ = self->__start__ + self->__member_size__ * self->__capacity__;
        return true;
    }
    else{
        self->__start__ = temp;
        return false;
    }
}

void *vector_get(vector_t *self, size_t index){
    if (index >= self->__member_count__)
        exit(-1);
    else
        return self->__start__ + index * self->__member_size__;
}

void vector_free(vector_t *self){
    free(self->__start__);
    free(self);
}