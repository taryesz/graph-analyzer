// this function assigns colors to the neighbors of the current vertex
bool compare_colors(vertex** graph, vertex* current_vertex, list* neighbors, bool* visited_vertices, int* bipartiteness) {

    // create an iterator through the neighbors list
    node* neighbor = neighbors->get_head();

    // iterate through the list of neighbors
    while (neighbor != nullptr) {

        // get the index of the current neighbor
        int neighbor_index = neighbor->get_content() - vertex_index_increment;

        // if the neighbor hasn't been visited yet ...
        if (!visited_vertices[neighbor_index]) {

            // visit the neighbor
            visited_vertices[neighbor_index] = true;

            // assign an opposite to the current vertex color to the current neighbor vertex
            bipartiteness[neighbor_index] = !bipartiteness[current_vertex->get_index() - vertex_index_increment];

            // if there is a collision of colors while assigning colors to the neighbors of the current neighbor, the graph is not bipartite
            if (!compare_colors(graph, graph[neighbor_index], graph[neighbor_index]->get_neighbors(), visited_vertices, bipartiteness)) return false;

        }

        // if the color of the neighbor is the same as of the current vertex (collision situation), the graph is not bipartite
        else if (bipartiteness[neighbor_index] == bipartiteness[current_vertex->get_index() - vertex_index_increment]) return false;

        // get the next neighbor from the list
        neighbor = neighbor->get_next();

    }

    // if no collisions were detected, the graph is bipartite
    return true;

}

// this function checks if the graph is bipartite
bool is_bipartite(vertex** graph, const int number_of_vertices) {

    // create an array to store the information about the visited vertices
    bool* visited_vertices = new bool[number_of_vertices];

    // create an array to store the assigned colors of each vertex in the graph
    int* bipartiteness = new int[number_of_vertices];

    // initialize the visited array and bipartiteness array
    for (int i = 0; i < number_of_vertices; i++) {

        visited_vertices[i] = false;        // all the vertices are unvisited by default
        bipartiteness[i] = default_value;   // all the colors aren't assigned by default

    }

    // iterate through the whole graph
    for (int i = 0; i < number_of_vertices; i++) {

        // if the current vertex is unvisited ...
        if (!visited_vertices[i]) {

            visited_vertices[i] = true;                     // visit the vertex
            bipartiteness[i] = default_bipartitenes_color;  // set a color for the vertex

            // assign colors for all the neighbors of the vertex, and, if there is a collision of colors ...
            if (!compare_colors(graph, graph[i], graph[i]->get_neighbors(), visited_vertices, bipartiteness)) {

                delete [] visited_vertices; // clean up memory
                delete [] bipartiteness;    // clean up memory

                printf("F\n");  // print the result
                return false;   // return the result

            }

        }

    }

    delete[] visited_vertices;  // clean up memory
    delete[] bipartiteness;     // clean up memory

    printf("T\n");  // print the result
    return true;    // return the result

}
