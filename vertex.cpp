#include "vertex.h"

vertex::vertex() {
    this->index = default_value;
    this->degree = default_value;
    this->neighbors = new list();
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
