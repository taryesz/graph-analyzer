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

    [[nodiscard]] node* pop();

    [[nodiscard]] node* get_head() const;

    [[nodiscard]] int count();

    void print();

};