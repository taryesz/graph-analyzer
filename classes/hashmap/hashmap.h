#include "hashnode.h"

class hashmap {
private:

    hashnode** table;
    int capacity;

public:

    explicit hashmap(int value);

    hashmap(const hashmap& other);

    hashmap& operator=(const hashmap& other);

    void insert(int key, int value);

    [[nodiscard]] int hash(int key) const;

    [[nodiscard]] int get(int key) const;

    ~hashmap();

};
