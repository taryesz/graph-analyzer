// this function calculates the number of missing edges to make the current graph a full one
int get_number_of_edge_complement(vertex* graph, const int number_of_vertices) {

    // create a variable to store the number of edges in the graph
    int total_number_of_edges = 0;

    // create an array to store the information about visited vertices
    bool visited_vertices[number_of_vertices];

    // fill in the visited array with false's by default
    for (int i = 0; i < number_of_vertices; i++) visited_vertices[i] = false;

    // iterate through the vertices of the graph
    for (int i = 0; i < number_of_vertices; i++) {

        visited_vertices[i] = true; // visit the current vertex

        // create the iterator through the neighbors list of the current vertex
        node* neighbor = graph[i].get_neighbors()->get_head();

        // iterate through the neighbor list
        while (neighbor != nullptr) {

            // get the current neighbor's index
            const int checked_vertex_index = neighbor->get_content();

            // if the neighbor has not been visited yet, increment the number of edges of the graph
            if (!visited_vertices[checked_vertex_index - vertex_index_increment]) ++total_number_of_edges;

            // get the next neighbor's index
            neighbor = neighbor->get_next();

        }

    }

    // calculate the number of edges in a full graph
    const int total_full_graph_number_of_edges = number_of_vertices * (number_of_vertices - 1) / 2;

    // calculate the number of missing edges to make the current graph a full one
    const int result = total_full_graph_number_of_edges - total_number_of_edges;

    printf("%d\n", result); // print the result
    return result;          // return the result

}