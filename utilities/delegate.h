#ifndef DELEGATE
#define DELEGATE



#define ACTION(name, args) void(*name)args
#define FUNC(name, return_type, args) return_type(*name)args



#endif
