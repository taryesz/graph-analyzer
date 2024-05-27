#include "list.h"

list::list() {
    this->head = nullptr;
}

void list::push(int content) {

    auto* new_node = new node();

    new_node->set_content(content);

    // if the stack is empty ...
    if (this->head == nullptr) {

        // set head as this same node
        this->head = new_node;

    }

    // if the stack is not empty ...
    else {

        // connect a new node to the first node in the stack
        new_node->set_next(this->head);

        // update the head
        this->head = new_node;

    }

}

void list::clear() {

    // get the head of the stack
    node* current = this->head;

    // while there are elements on the stack
    while (current != nullptr) {

        // get the next symbol from the stack
        node* next = current->get_next();

        // delete the currently parsed symbol
        delete current;

        // update the currently parsed symbol with the next element
        current = next;

    }

    // after deleting all elements from the stack, make sure the key nodes are set to null
    this->head = nullptr;

}

node* list::get_head() const {
    return head;
}
