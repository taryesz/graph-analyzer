template <typename Type>
void initiate_array(Type* array, const int size, int default_data = default_value) {
    for (int i = 0; i < size; i++) {
        array[i] = default_data;
    }
}