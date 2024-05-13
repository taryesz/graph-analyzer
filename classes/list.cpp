#include "list.h"

list::list() {
    this->head = nullptr;
    this->tail = nullptr;
}

void list::push(int content) {

    auto* new_node = new node();

    new_node->set_content(content);

    // if the stack is empty ...
    if (this->head == nullptr) {

        // set both head & tail as the same node
        this->head = new_node;
        this->tail = new_node;

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
    this->tail = nullptr;

}

[[nodiscard]] node* list::pop() {

    // if the head of the stack doesn't exist, return null
    if (this->head == nullptr) return nullptr;

    // if the head exists, get it
    node* popped = this->head;

    // if there was only one element on the stack and the program has popped it, set to null both head and tail
    if (this->head == this->tail) {
        this->head = nullptr;
        this->tail = nullptr;
    }

    // if there were more than one element on the stack, scoot the whole stack by one 'to the left'
    else this->head = this->head->get_next();

    // reset the popped's connection
    popped->set_next(nullptr);

    // return the popped symbol
    return popped;

}

[[nodiscard]] node* list::get_head() const {
    return head;
}

[[nodiscard]] int list::count() {

    node* iterator = this->head;
    int counter = 0;

    // while there are elements on the stack
    while (iterator != nullptr) {

        ++counter;

        // get the next symbol from the stack
        iterator = iterator->get_next();

    }

    // print the new line char for the sake of aesthetic look of the output
    return counter;

}

void list::print() {

    node* iterator = this->head;

    // while there are elements on the stack
    while (iterator != nullptr) {

        printf("%d ", iterator->get_content());

        // get the next symbol from the stack
        iterator = iterator->get_next();

    }

}