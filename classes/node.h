#include "../define.h"

class node {
private:

    int content;
    node* next;

public:

    node();

    void set_content(int value);

    void set_next(node* value);

    [[nodiscard]] int get_content() const;

    [[nodiscard]] node* get_next() const;

};