// this function merges two sub-arrays
void merge(int* array, int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    // create temporary arrays
    int* left_half = new int[n1];
    int* right_half = new int[n2];

    // copy data to temporary arrays
    for (int i = 0; i < n1; i++) left_half[i] = array[left + i];
    for (int i = 0; i < n2; i++) right_half[i] = array[mid + 1 + i];

    // merge the temporary arrays back into the original array
    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (left_half[i] >= right_half[j]) {
            array[k] = left_half[i];
            i++;
        } else {
            array[k] = right_half[j];
            j++;
        }
        k++;
    }

    // copy the remaining elements of leftArray, if any
    while (i < n1) {
        array[k] = left_half[i];
        i++;
        k++;
    }

    // copy the remaining elements of rightArray, if any
    while (j < n2) {
        array[k] = right_half[j];
        j++;
        k++;
    }

    // clean up temporary arrays
    delete [] left_half;
    delete [] right_half;
}

// this function sorts the array using mergesort
void sort(int* array, int left, int right) {

    if (left < right) {

        // calculate the index which determines the middle of an array
        int mid = left + (right - left) / 2;

        // sort the first half
        sort(array, left, mid);

        // sort the second half
        sort(array, mid + 1, right);

        // merge the sorted halves
        merge(array, left, mid, right);

    }

}

// this function calculates the graph's degree sequence
void get_degree_sequence(vertex** graph, const int number_of_vertices) {

    // create an array to store the degree sequence
    int* degree_sequence = new int[number_of_vertices];

    // copy all the vertices' degrees into the new array
    for (int i = 0; i < number_of_vertices; i++) degree_sequence[i] = graph[i]->get_degree();

    // sort the degree array in descending order using merge sort
    sort(degree_sequence, 0, number_of_vertices - 1);

    // print the array
    for (int i = 0; i < number_of_vertices; i++) printf("%d ", degree_sequence[i]);
    printf("\n");

    // clean up the allocated memory
    delete [] degree_sequence;

}
