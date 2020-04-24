cmake_minimum_required(VERSION 3.13)
project(CS103 C)

set(CMAKE_C_STANDARD 11)

add_executable(CS103
        AVL.c
        BST.c
        Chaining.c
        "circular list.c"
        heap.c
        Linear_Probing.c
        "list merge sort .c"
        "post_in order.h"
        "quick  sort.c")
