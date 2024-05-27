#include "node.h"

class list {
private:

    node* head;

public:

    list();

    void push(int content);

    void clear();

    [[nodiscard]] node* get_head() const;

};
