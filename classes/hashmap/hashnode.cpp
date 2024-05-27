#include "hashnode.h"

hashnode::hashnode() {
    this->key = default_value;
    this->value = default_value;
    this->next = nullptr;
}

void hashnode::set_key(int v) {
    this->key = v;
}

void hashnode::set_value(int v) {
    this->value = v;
}

void hashnode::set_next(hashnode *v) {
    this->next = v;
}

int hashnode::get_key() const {
    return this->key;
}

int hashnode::get_value() const {
    return this->value;
}

hashnode* hashnode::get_next() const {
    return this->next;
}
