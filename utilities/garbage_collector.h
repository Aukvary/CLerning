#ifndef GC
#define GC
void *gc_virtual_memory[10000];
unsigned long last_index = 0;

typedef struct my_ptr{
    unsigned long index;
}ptr_t;

void add_ptr_to_virtual_memory(void *ptr){
    gc_virtual_memory[last_index] = ptr;
}
#endif
