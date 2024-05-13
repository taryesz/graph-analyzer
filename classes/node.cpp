#include "node.h"

node::node() {
    this->content = default_value;
    this->next = nullptr;
}

void node::set_content(int value) {
    this->content = value;
}

void node::set_next(node* value) {
    this->next = value;
}

[[nodiscard]] int node::get_content() const {
    return this->content;
}

[[nodiscard]] node* node::get_next() const {
    return this->next;
}
