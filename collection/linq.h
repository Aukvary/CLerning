#ifndef LINQ
#define LINQ

#define LEN(collection) ({collection->__len__(collection);})

#define FOR(type, el, collection, action)({ \
iterator_t iter = collection->__iterator__; \
iter.start(collection);                       \
type el = *(type *)iter.next(collection);  \
while (!iter.end(collection)){              \
action;                                     \
el = *(type *)iter.next(collection) ;}\
});

#endif
