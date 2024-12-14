#ifndef ITERATOR
#define ITERATOR

typedef struct {
    void(*start)(void *);
    void *(*next)(void *);
    bool(*end)(void *);
}iterator_t;
#endif
