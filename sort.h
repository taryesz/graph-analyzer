// this function merges two sub-arrays
void merge(vertex** graph, int left, int middle, int right) {

    int size_left = middle - left + 1;
    int size_right = right - middle;

    // create temporary arrays
    vertex** left_array = new vertex*[size_left];
    vertex** right_array = new vertex*[size_right];

    // copy data to temporary arrays
    for (int i = 0; i < size_left; i++) left_array[i] = graph[left + i];
    for (int i = 0; i < size_right; i++) right_array[i] = graph[middle + 1 + i];

    // merge the temporary arrays back into the original array
    int index_left = 0;
    int index_right = 0;
    int index_merged = left;

    while (index_left < size_left && index_right < size_right) {

        if (left_array[index_left]->get_degree() >= right_array[index_right]->get_degree()) {
            graph[index_merged] = left_array[index_left];
            index_left++;
        }
        else {
            graph[index_merged] = right_array[index_right];
            index_right++;
        }
        index_merged++;

    }

    // copy the remaining elements of left_array, if any
    while (index_left < size_left) {
        graph[index_merged] = left_array[index_left];
        index_left++;
        index_merged++;
    }

    // copy the remaining elements of right_array, if any
    while (index_right < size_right) {
        graph[index_merged] = right_array[index_right];
        index_right++;
        index_merged++;
    }

    // clean up temporary arrays
    delete[] left_array;
    delete[] right_array;

}

// this function sorts the array using mergesort
void sort(vertex** graph, int left, int right) {

    if (left < right) {

        // calculate the index which determines the middle of an array
        int middle = left + (right - left) / 2;

        // sort the first half
        sort(graph, left, middle);

        // sort the second half
        sort(graph, middle + 1, right);

        // merge the sorted halves
        merge(graph, left, middle, right);

    }

}
