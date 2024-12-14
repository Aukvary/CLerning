#ifndef ARRAY
#define ARRAY
#include "../iterator.h"
#include <stdlib.h>


typedef struct vector_s{
    iterator_t __iterator__;
    size_t __current_iterator_member_index__;

    size_t __member_size__;
    size_t __member_count__;
    size_t __capacity__;

    void *__start__;
    void *__end__;

    size_t (*__len__)(struct vector_s *);
}vector_t;

vector_t *new_vector(size_t member_size, size_t capacity);

size_t vector_len(vector_t* self);

void vector_iterator_start(void *self);
void *vector_iterator_next(void *self);
bool vector_iterator_end(void *self);

#define vector_push(self, new_element) {                        \
    if (self->__capacity__ <= self->__member_count__) {         \
        if (!vector_extend(self))                               \
            exit( -1 );                                         \
    }                                                           \
    ((typeof(new_element) *)                                    \
    (self->__start__))[self->__member_count__] = new_element;   \
    self->__member_count__++;                                   \
}

#define vector_remove(self, element)({                                          \
typeof(element) *cur = self->__start__;                                         \
while (cur != self->__end__){                                                   \
    if (element == *cur) {                                                      \
        self->__member_count__--;                                               \
        break;                                                                  \
    }                                                                           \
    cur++;                                                                      \
}                                                                               \
while (cur != self->__end__){                                                   \
    *cur = *(cur + 1);                                                          \
    cur++;                                                                      \
}                                                                               \
})

bool vector_extend(vector_t *self);

void *vector_get(vector_t *self, size_t index);

#define vector_set(self, index, value)({ \
((typeof(value) *)self->__start__)[index] = value;\
})

void vector_free(vector_t *self);


#define new_vector_from(array) ({                           \
int len = sizeof(array) / sizeof(array[0]);                 \
vector_t *self = malloc(sizeof(vector_t));                  \
                                                            \
self->__iterator__.start = vector_iterator_start;           \
self->__iterator__.next = vector_iterator_next;             \
self->__iterator__.end = vector_iterator_end;               \
                                                            \
self->__capacity__ = len;                                   \
self->__member_size__ = len;                                \
                                                            \
self->__start__ = array;                                    \
self->__end__ = self->__start__ + len * sizeof(array[0]);   \
self;                                                       \
})
#endif
