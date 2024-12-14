cmake_minimum_required(VERSION 3.28)
project(untitled C)

set(CMAKE_C_STANDARD 23)

add_executable(untitled main.c
        collection/nodes.h

        collection/list.h
        collection/list.c

        collection/loop_list.h
        collection/loop_list.c

        vector2.h
        vector2.c
        collection/vector/vector.h
        collection/linq.h
        collection/iterator.h
        collection/vector/vector.c
)






