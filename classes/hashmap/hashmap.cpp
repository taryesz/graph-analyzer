#include "hashmap.h"

hashmap::hashmap(int value) {

    // initiate the map capacity with a value specified by a user creating the instance of this object
    this->capacity = value;

    // create and initiate the array of the same size as the capacity
    this->table = new hashnode*[this->capacity];
    for (int i = 0; i < this->capacity; i++) this->table[i] = nullptr;

}

hashmap::hashmap(const hashmap& other) {

    // assign values from the other object to the current one
    this->capacity = other.capacity;

    // create a new dynamic member
    this->table = new hashnode*[this->capacity];

    // iterate through the other object's dynamic member
    for (int i = 0; i < this->capacity; i++) {

        // if the element under the current index wasn't initiated, in the new dynamic member don't initiate it either
        if (other.table[i] == nullptr) this->table[i] = nullptr;

        // otherwise ...
        else {

            // create a pointer to the current object in the other table
            hashnode* source_node = other.table[i];

            // create a new object in the new table with the same values as the other's one
            // (since objects of type "hashnode" don't have dynamic members,
            // the program will use the default copy constructor)
            this->table[i] = new hashnode(*source_node);

            // create a pointer to the current object in the new table
            hashnode* target_node = this->table[i];

            // while there are elements in the other "hashlist" ...
            while (source_node->get_next() != nullptr) {

                // save the pointer to the next element
                source_node = source_node->get_next();

                // link the newly created node based on "source_node" to the previous one
                target_node->set_next(new hashnode(*source_node));

                // get the next element
                target_node = target_node->get_next();

            }

        }

    }

}

hashmap& hashmap::operator=(const hashmap& other) {

    // if the object is being assigned to itself, return this very object
    if (this == &other) return *this;

    // iterate through the current table
    for (int i = 0; i < this->capacity; i++) {

        // create a pointer to the current element
        hashnode* current = this->table[i];

        // while there are elements on the "hashlist" ...
        while (current != nullptr) {

            // create a pointer to the next element in the "hashlist"
            hashnode* next = current->get_next();

            // delete the current object
            delete current;

            // update the current object
            current = next;

        }

    }

    // delete the table itself
    delete [] this->table;

    // assign values from the other object to the current one
    this->capacity = other.capacity;

    // create a new dynamic member
    this->table = new hashnode*[this->capacity];

    // iterate through the other object's dynamic member
    for (int i = 0; i < this->capacity; i++) {

        // if the element under the current index wasn't initiated, in the new dynamic member don't initiate it either
        if (other.table[i] == nullptr) this->table[i] = nullptr;

            // otherwise ...
        else {

            // create a pointer to the current object in the other table
            hashnode* source_node = other.table[i];

            // create a new object in the new table with the same values as the other's one
            // (since objects of type "hashnode" don't have dynamic members,
            // the program will use the default copy constructor)
            this->table[i] = new hashnode(*source_node);

            // create a pointer to the current object in the new table
            hashnode* target_node = this->table[i];

            // while there are elements in the other "hashlist" ...
            while (source_node->get_next() != nullptr) {

                // save the pointer to the next element
                source_node = source_node->get_next();

                // link the newly created node based on "source_node" to the previous one
                target_node->set_next(new hashnode(*source_node));

                // get the next element
                target_node = target_node->get_next();

            }

        }

    }

    return *this;

}

void hashmap::insert(int key, int value) {

    // encode the key using hash-function
    // i.e. determine the index in the array where this key:value pair is going to be stored under
    int hash_index = hash(key);

    // create an iterator
    hashnode* previous = nullptr;

    // create an iterator to traverse the map
    hashnode* iterator = this->table[hash_index];

    // iterate through the list under this index in the array until the end of this list or
    // until this key already occurs here in this spot
    // (meaning that the value stored under this key has to be overwritten)
    while (iterator != nullptr && iterator->get_key() != key) {

        // keep track of the penultimate nodes
        previous = iterator;

        // get the next element
        iterator = iterator->get_next();

    }

    // if the whole list was traversed and there isn't this key's occurrence ...
    if (iterator == nullptr) {

        // create a new node
        iterator = new hashnode();

        // set its properties
        iterator->set_key(key);
        iterator->set_value(value);

        // if this hash index didn't store anything, make this new node its first element by setting it as the head of the list
        if (previous == nullptr) table[hash_index] = iterator;

        // otherwise, if there is so-called "collision", connect the new node to the existing one (since both of the nodes are located under the same hash index)
        else previous->set_next(iterator);

    }

    // the specified key was found, so replace the old value with the new one
    else iterator->set_value(value);

}

int hashmap::hash(int key) const {
    return key % this->capacity;
}

int hashmap::get(int key) const {

    // encode the key using hash-function
    int hash_index = hash(key);

    // create an iterator (find the list of pairs under the generated hash)
    hashnode* iterator = table[hash_index];

    // while there are elements in this list ...
    while (iterator != nullptr) {

        // if the current node's key is the one we are looking for, return a value associated with it
        if (iterator->get_key() == key) return iterator->get_value();

        // otherwise, get the next node
        iterator = iterator->get_next();

    }

    // if the key wasn't found, return default value
    return default_value;

}

hashmap::~hashmap() {

    // iterate through the whole map
    for (int i = 0; i < this->capacity; i++) {

        // get the head of the current bucket
        hashnode* current = this->table[i];

        // while there are elements in the bucket
        while (current != nullptr) {

            // get the next node in the bucket
            hashnode* next = current->get_next();

            // delete the current node
            delete current;

            // move to the next node
            current = next;

        }

        // after deleting all nodes in the bucket, make sure the head is set to null
        table[i] = nullptr;

    }

    // delete the table array itself
    delete[] table;

}
