// this function is the implementation of the DFS traversal which visits the neighboring vertices of a vertex
void traverse_graph(vertex** graph, vertex* current_vertex, hashmap* graph_hashmap, bool* visited_vertices) {

    // create the iterator through the neighbors list
    node* neighbor = current_vertex->get_neighbors()->get_head();

    // iterate through the neighbor list
    while (neighbor != nullptr) {

        // get the current neighbor's index and find its cardinality index
        int neighbor_index = graph_hashmap->get(neighbor->get_content());

        // if the neighbor has not been visited yet ...
        if (!visited_vertices[neighbor_index]) {

            // visit the neighbor
            visited_vertices[neighbor_index] = true;

            // launch the traversal mechanism on the neighbor
            traverse_graph(graph, graph[neighbor_index], graph_hashmap, visited_vertices);

        }

        // get the next neighbor's index
        neighbor = neighbor->get_next();

    }

}

// this function checks how many parts the graph consists of
int get_connectivity_number(vertex** graph, const int number_of_vertices) {

    // create a variable that stores the information about the number of parts in the graph
    int result = default_components_count;

    // create an array to store the information about visited vertices
    bool* visited_vertices = new bool[number_of_vertices];

    // initiate this array with false's
    initiate_array(visited_vertices, number_of_vertices, false);

    // create a hashmap to store pairs of vertex's index : cardinality index
    auto* graph_hashmap = new hashmap(number_of_vertices);

    // populate the hashmap (vertex's index : cardinality index)
    for (int i = 0; i < number_of_vertices; i++) graph_hashmap->insert(graph[i]->get_index(), i);

    // iterate through the whole array of vertices
    for (int vertex_counter = 0; vertex_counter < number_of_vertices; vertex_counter++) {

        // if the program processes the next vertices (not the first one)
        if (vertex_counter > 0) {

            // if the currently processed vertex has not been visited, it means it is not connected to the rest of the graph, so increment the number of parts of the graph
            if (!visited_vertices[vertex_counter]) ++result;

            // otherwise, skip the iteration (the program doesn't need to process all the processed vertices one more time)
            else continue;

        }

        // visit the current vertex
        visited_vertices[vertex_counter] = true;

        // check the vertex's neighbors
        traverse_graph(graph, graph[vertex_counter], graph_hashmap, visited_vertices);

    }

    // clean memory up
    delete [] visited_vertices;
    delete graph_hashmap;

    printf("%d\n", result); // print the result
    return result;          // return the result

}
