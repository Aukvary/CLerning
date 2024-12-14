#ifndef VECTOR2
#define VECTOR2


typedef struct vec2{
    float _x;
    float _y;
}vec2_t;

/*const vec2_t vec2_zero = {0, 0};
const vec2_t vec2_up = {0, 1};
const vec2_t vec2_down = {0, -1};
const vec2_t vec2_right = {1, 0};
const vec2_t vec2_left = {-1, 0};*/

vec2_t new_vec2(float x, float y);
vec2_t* add_to_vec2(vec2_t* self, vec2_t* add_value);


#define VEC2(arg1, operator, arg2)\
new_vec2(arg1._x operator arg2._x, arg1._y operator arg2._y)



#endif
