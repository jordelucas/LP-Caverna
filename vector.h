#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

template<typename Element>
struct vector {
    vector(int initial_quantity);
    ~vector();

    int * values;
    int quantity;
    int array_size;

    int at(int index);
    void set(int index, Element element);
    void insert(int index, Element element);
    int erase(int index);
    int size();
    bool empty();
};

template<typename Element>
vector<Element>::vector(int initial_quantity) {
    values = new int[initial_quantity];
    array_size = initial_quantity;
    quantity = 0;
}

template<typename Element>
vector<Element>::~vector () {
    delete[] values;
}

template<typename Element>
int vector<Element>::at(int index) {
    return values[index];
}

template<typename Element>
void vector<Element>::set(int index, Element value) {
    values[index] = value;
}

template<typename Element>
void vector<Element>::insert(int index, Element value) {
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

template<typename Element>
int vector<Element>::erase(int index) {
    for(int i = index; i < quantity-1; i++) {
        values[i] = values[i+1];
    }
    quantity--;
    return values[index];
}

template<typename Element>
int vector<Element>::size() {
    return quantity;
}

template<typename Element>
bool vector<Element>::empty() {
    return quantity == 0;
}
#endif // !VECTOR_H

