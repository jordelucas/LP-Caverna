#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

#include "Quadrado.h"

struct vector {
    vector(int initial_quantity);
    ~vector();
    
    Quadrado * values;
    int quantity;
    int array_size;

    Quadrado at(int index);
    void set(int index, Quadrado *quadrado);
    void insert(int index, Quadrado *quadrado);
    Quadrado erase(int index);
    int size();
    bool empty();
};

#endif