#include "define.h"

class hashnode {
private:

    int key;
    int value;
    hashnode* next;

public:

    hashnode();

    void set_key(int v);

    void set_value(int v);

    void set_next(hashnode* v);

    [[nodiscard]] int get_key() const;

    [[nodiscard]] int get_value() const;

    [[nodiscard]] hashnode* get_next() const;

};