#include <iostream>

#include "vector.h"

vector::vector(int initial_quantity) {
    values = new int[initial_quantity];
    array_size = initial_quantity;
    quantity = 0;
}

vector::~vector () {
    delete[] values;
}

int vector::at(int index) {
    return values[index];
}

void vector::set(int index, int value) {
    values[index] = value;
}

void vector::insert(int index, int value) {
    if(quantity == array_size) {
        int * temp = new int[array_size + 1];
        for (int i = 0; i < array_size; i++) {
            temp[i] = values[i];
        }
        delete[] values;
        values = temp;
        array_size = array_size + 10;
    }
    
    for(int i = quantity; i > index; i--) {
        values[i] = values[i-1];
    }
    values[index] = value;
    quantity++;
}

int vector::erase(int index) {
    for(int i = index; i < quantity-1; i++) {
        values[i] = values[i+1];
    }
    quantity--;
    return values[index];
}

int vector::size() {
    return quantity;
}

bool vector::empty() {
    return quantity == 0;
}