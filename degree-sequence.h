// this function calculates the graph's degree sequence
void get_degree_sequence(vertex** graph, const int number_of_vertices) {

    // create a copy of the graph not to sort it globally
    auto** graph_copy = new vertex*[number_of_vertices];

    // copy all the elements from the original graph to its copy
    for (int i = 0; i < number_of_vertices; i++) graph_copy[i] = graph[i];

    // sort the graph by degrees in descending order using merge sort
    sort(graph_copy, 0, number_of_vertices - 1);

    // print the sorted degrees
    for (int i = 0; i < number_of_vertices; i++) printf("%d ", graph_copy[i]->get_degree());

    // print newline symbol for aesthetic purposes
    printf("\n");

    // clean memory up
    delete [] graph_copy;

}
