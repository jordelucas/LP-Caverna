template<typename Element>
struct vector {
    vector(int initial_quantity);
    ~vector();

    int * values;
    int quantity;
    int array_size;

    int at(int index);
    void set(int index, <Element>);
    void insert(int index, <Element>);
    int erase(int index);
    int size();
    bool empty();
};