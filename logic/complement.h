// this function calculates the number of missing edges to make the current graph a full one
long long int get_number_of_edge_complement(vertex** graph, const long long int number_of_vertices) {

    // create a divisor for a handshake lemma
    const long long int handshake_lemma_divisor = 2;

    // create a variable to store the number of edges in the graph
    long long int total_number_of_edges = 0;

    // iterate through the vertices of the graph and add the degree of each vertex to the sum
    for (long long int i = 0; i < number_of_vertices; i++) total_number_of_edges += graph[i]->get_degree();

    // according to the handshake lemma, the sum of the graph degrees has to be divided by two
    total_number_of_edges /= handshake_lemma_divisor;

    // calculate the number of edges in a full graph
    const long long int total_full_graph_number_of_edges = number_of_vertices * (number_of_vertices - 1) / 2;

    // calculate the number of missing edges to make the current graph a full one
    const long long int result = total_full_graph_number_of_edges - total_number_of_edges;

    printf("%lld\n", result); // print the result
    return result;            // return the result

}