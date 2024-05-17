#include "list.h"

class vertex {
private:

    int index;
    int degree;
    list* neighbors;

public:

    vertex();

    void set_index(int value);

    void set_degree(int value);

    // void set_neighbors(list* value);

    int get_index() const;

    int get_degree() const;

    list* get_neighbors() const;

    ~vertex();

};
