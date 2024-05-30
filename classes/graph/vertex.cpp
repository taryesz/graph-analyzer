#include "vertex.h"

vertex::vertex() {
    this->index = default_value;
    this->degree = default_value;
    this->neighbors = new list();
}

vertex::vertex(const vertex& other) {

    // assign values from the other object to the current one
    this->index = other.index;
    this->degree = other.degree;

    // create a new dynamic member
    this->neighbors = new list();

    // create an iterator
    node* iterator = other.neighbors->get_head();

    // iterate through the list of the other object
    while (iterator != nullptr) {

        // copy the current element to the new list
        this->neighbors->push(iterator->get_content());

        // get the next element
        iterator = iterator->get_next();

    }

}

vertex& vertex::operator=(const vertex& other) {

    // if the object is being assigned to itself, return this very object
    if (this == &other) return *this;

    // clean the existing list
    this->neighbors->clear();

    // delete the existing list
    delete this->neighbors;

    // assign values from the other object to the current one
    this->index = other.index;
    this->degree = other.degree;

    // create a new dynamic member
    this->neighbors = new list();

    // create an iterator
    node* iterator = other.neighbors->get_head();

    // iterate through the list of the other object
    while (iterator != nullptr) {

        // copy the current element to the new list
        this->neighbors->push(iterator->get_content());

        // get the next element
        iterator = iterator->get_next();

    }

    // return the newly defined object
    return *this;

}

void vertex::set_index(int value) {
    this->index = value;
}

void vertex::set_degree(int value) {
    this->degree = value;
}

int vertex::get_index() const {
    return this->index;
}

int vertex::get_degree() const {
    return this->degree;
}

list* vertex::get_neighbors() const {
    return this->neighbors;
}

vertex::~vertex() {
    this->neighbors->clear();
    delete this->neighbors;
}
