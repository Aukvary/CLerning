#include <stdio.h>
#include "collection/vector/vector.h"
#include "collection/linq.h"

typedef struct s{
    int num;
    unsigned char symbol;
}s_t;

int main(){
    s_t vals[4] = {
            {10, 'a'},
            {20, 'b'},
            {30, 'c'},
            {40, 'd'}
    };

    vector_t *vector = new_vector(sizeof(s_t), 0);
    vector_push(vector, vals[0])
    vector_push(vector, vals[1])
    vector_push(vector, vals[2])
    vector_push(vector, vals[3])

    FOR(s_t, el, vector,{
        printf("el.symbol = %c\tel.num = %d\n", el.symbol, el.num);
    })

    vector_free(vector);
    return 0;
}