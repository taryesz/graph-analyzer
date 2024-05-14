void traverse_graph(vertex* graph, vertex current_vertex, bool* visited_vertices) {

    // create the iterator through the neighbors list
    node* neighbor = current_vertex.get_neighbors()->get_head();

    // iterate through the neighbor list
    while (neighbor != nullptr) {

        // get the current neighbor's index
        const int checked_vertex_index = neighbor->get_content();

        // printf("checking vertex v%d ...\n", checked_vertex_index);

        // if the neighbor is already visited - don't do anything
        if (visited_vertices[checked_vertex_index - vertex_index_increment]) {
            // printf("the vertex v%d is already visited\n", checked_vertex_index);
            // skip
        }

        // if the neighbor has not been visited yet ...
        else {

            // printf("the vertex v%d is not yet visited\n", checked_vertex_index);

            // visit the neighbor
            visited_vertices[checked_vertex_index - vertex_index_increment] = true;

            // printf("visited the vertex v%d\n", checked_vertex_index);

            // launch the traversal mechanism on the neighbor
            traverse_graph(graph, graph[checked_vertex_index - vertex_index_increment], visited_vertices);

        }

        // get the next neighbor's index
        neighbor = neighbor->get_next();

    }

}

bool is_connected(vertex* graph, const int number_of_vertices) {

    // create an array to store the information about visited vertices
    bool visited_vertices[number_of_vertices];

    // fill in the visited array with false's by default
    for (int i = 0; i < number_of_vertices; i++) visited_vertices[i] = false;

    // iterate through the whole array of vertices
    for (int vertex_counter = 0; vertex_counter < number_of_vertices; vertex_counter++) {

        // printf("START: v%d\n", i + vertex_index_increment);

        // if the program processes the next vertices (not the first one)
        if (vertex_counter > 0) {

            // if the currently processed vertex has not been visited ...
            if (!visited_vertices[vertex_counter]) {

                // for (int k = 0; k < number_of_vertices; k++) printf("%d ", visited_vertices[k]);
                printf("F\n"); // ... it means that this vertex is not connected to the rest of the graph,
                return false;  // so just return "F"
            }

            // otherwise, skip the iteration (the program doesn't need to process all the processed vertices one more time)
            else continue;

        }

        // visit the current vertex
        visited_vertices[vertex_counter] = true;

        // check the vertex's neighbors
        traverse_graph(graph, graph[vertex_counter], visited_vertices);

    }

    // for (int i = 0; i < number_of_vertices; i++) printf("%d ", visited_vertices[i]);
    // printf("\n");

    printf("T\n"); // if the graph is connected, just return "T"
    return true;

}