#include "../list/list.h"

class vertex {
private:

    int index;
    int degree;
    list* neighbors;

public:

    vertex();

    void set_index(int value);

    void set_degree(int value);

    [[nodiscard]] int get_index() const;

    [[nodiscard]] int get_degree() const;

    [[nodiscard]] list* get_neighbors() const;

    ~vertex();

};
