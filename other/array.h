// this function fills an array with data
template <typename Type>
void initiate_array(Type* array, const int size, int default_data = default_value) {
    for (int i = 0; i < size; i++) {
        array[i] = default_data;
    }
}

// this function resets the array of colors (but more efficiently)
// i.e. instead of resetting a gigantic array of data, when even most of its data hasn't been changed,
// we use a list of changed data (list of indices where the data was changed) and reset only those that were actually changed
template <typename Type>
void reset_array(list* affected_data, Type* array) {

    // create an iterator
    node* iterator = affected_data->get_head();

    // iterate through the list
    while (iterator != nullptr) {

        // set the color as available
        array[iterator->get_content()] = false;

        // get the next element
        iterator = iterator->get_next();

    }

}