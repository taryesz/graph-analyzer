// this function calculates the graphs degree sequence
void get_degree_sequence(vertex* graph, const int number_of_vertices) {

    // create an array to store the degree sequence
    int degree_sequence[number_of_vertices];

    // copy all the vertices' degrees into the new array
    for (int i = 0; i < number_of_vertices; i++) degree_sequence[i] = graph[i].get_degree();

    // sort (bubble sort) the degree array in descending order
    for (int i = 0; i < number_of_vertices - 1; i++) {
        for (int j = 0; j < number_of_vertices - i - 1; j++) {
            if (degree_sequence[j] < degree_sequence[j + 1]) {
                int temp = degree_sequence[j];
                degree_sequence[j] = degree_sequence[j + 1];
                degree_sequence[j + 1] = temp;
            }
        }
    }

    // print the array
    for (int i = 0; i < number_of_vertices; i++) printf("%d ", degree_sequence[i]);
    printf("\n");

}