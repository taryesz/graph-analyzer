#include "../list/list.h"

class vertex {
private:

    int index;
    int degree;
    list* neighbors;

public:

    vertex();

    vertex(const vertex& other);

    vertex& operator=(const vertex& other);

    void set_index(int value);

    void set_degree(int value);

    [[nodiscard]] int get_index() const;

    [[nodiscard]] int get_degree() const;

    [[nodiscard]] list* get_neighbors() const;

    ~vertex();

};
