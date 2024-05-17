#include "node.h"
#include <iostream>

class list {
private:

    node* head;
    node* tail;

public:

    list();

    void push(int content);

    void clear();

    // node* pop();

    node* get_head() const;

    // node* get_tail() const;

    // int count();

    // void print();

};