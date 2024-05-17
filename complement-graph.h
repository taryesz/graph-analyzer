// this function calculates the number of missing edges to make the current graph a full one
int get_number_of_edge_complement(vertex** graph, const int number_of_vertices) {

    // create a divisor for a handshake lemma
    const int handshake_lemma_divisor = 2;

    // create a variable to store the number of edges in the graph
    int total_number_of_edges = 0;

    // iterate through the vertices of the graph and add the degree of each vertex to the sum
    for (int i = 0; i < number_of_vertices; i++) total_number_of_edges += graph[i]->get_degree();

    // according to the handshake lemma, the sum of the graph degrees has to be divided by two
    total_number_of_edges /= handshake_lemma_divisor;

    // calculate the number of edges in a full graph
    const int total_full_graph_number_of_edges = number_of_vertices * (number_of_vertices - 1) / 2;

    // calculate the number of missing edges to make the current graph a full one
    const int result = total_full_graph_number_of_edges - total_number_of_edges;

    printf("%d\n", result); // print the result
    return result;          // return the result

}