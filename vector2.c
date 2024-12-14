#include "vector2.h"

vec2_t new_vec2(float x, float y){
    vec2_t self = {x, y};
    return self;
}

vec2_t* add_to_vec2(vec2_t* self, vec2_t* add_value){
    self->_x += add_value->_x;
    self->_y += add_value->_y;

    return self;
}
