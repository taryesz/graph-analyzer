// this function returns the first available color
int get_next_available_color(const bool* available_colors, const int number_of_vertices) {

    // iterate through the array of colors
    for (int i = 0; i < number_of_vertices; i++) {

        // if this color is available (hasn't been used), return it
        if (!available_colors[i]) return i + vertex_index_increment;

    }

    // default return
    return number_of_vertices + vertex_index_increment;

}

// this function colors all the vertices in the graph so that no 2 adjacent vertices have the same color
void color_graph(vertex** graph, const int number_of_vertices, bool largest_first = false, const int* indices = nullptr) {

    // create an array that will store the final result
    int* result_colors = new int[number_of_vertices];

    // initiate the array with the default value
    initiate_array(result_colors, number_of_vertices);

    // set the first vertex's color to 1
    result_colors[0] = default_coloring_color;

    // create an array to store the information about what colors can be used to color the neighbors
    bool* available_colors = new bool[number_of_vertices];

    // initiate the array with false's meaning that all colors are available
    initiate_array(available_colors, number_of_vertices, false);

    // create a list to store the colored neighbors of each vertex (for time complexity purposes)
    auto* colored_neighbors = new list();

    // create a map to store the vertex identifier to index mapping
    auto* graph_hashmap = new hashmap(number_of_vertices);

    // populate the graph hashmap (key as a vertex's index and value as its cardinal number)
    for (int i = 0; i < number_of_vertices; i++) graph_hashmap->insert(graph[i]->get_index(), i);

    // iterate through the graph starting with the second vertex
    for (int i = 1; i < number_of_vertices; i++) {

        // reset the available colors array
        reset_array(colored_neighbors, available_colors);

        // clear the list of colored neighbors
        colored_neighbors->clear();

        // get the first neighbor of the current vertex
        node* neighbor = graph[i]->get_neighbors()->get_head();

        // iterate through the list of neighbors of the current vertex
        while (neighbor != nullptr) {

            // get the current neighbor's index and find its cardinality index
            int neighbor_index = graph_hashmap->get(neighbor->get_content());

            // if this neighbor has already been colored ...
            if (result_colors[neighbor_index] != default_value) {

                // mark this color as unavailable
                available_colors[result_colors[neighbor_index] - vertex_index_increment] = true;

                // save the neighbor to the list
                colored_neighbors->push(result_colors[neighbor_index] - vertex_index_increment);

            }

            // get the next neighbor
            neighbor = neighbor->get_next();

        }

        // get the first available color
        int color_of_vertex = get_next_available_color(available_colors, number_of_vertices);

        // assign the found color to the current vertex
        result_colors[i] = color_of_vertex;

    }

    // if the LF-coloring is being applied ...
    if (largest_first && indices) {

        // create a hashmap to hold the colors in the original order
        auto* colors_hashmap = new hashmap(number_of_vertices);

        // populate the colors hashmap (original index : corresponding color)
        for (int i = 0; i < number_of_vertices; i++) colors_hashmap->insert(indices[i], result_colors[i]);

        // print the colors in the original order
        for (int i = 0; i < number_of_vertices; i++) printf("%d ", colors_hashmap->get(i));

        // clean memory up
        delete colors_hashmap;

    }

    // otherwise, use greedy coloring
    else {

        // print the result
        for (int i = 0; i < number_of_vertices; i++) printf("%d ", result_colors[i]);

    }

    // print newline symbol for aesthetic purposes
    printf("\n");

    // clean up memory
    delete[] result_colors;
    delete[] available_colors;
    colored_neighbors->clear();
    delete colored_neighbors;
    delete graph_hashmap;

}

// this function specifies that the coloring technique a user wants to color a graph with is LF
void color_graph_largest_first(vertex** graph, const int number_of_vertices) {

    // create an array to store the indices of the original graph to print the result in the correct order
    int* indices = new int[number_of_vertices];

    // sort the graph by degrees in descending order
    sort(graph, 0, number_of_vertices - 1);

    // populate the indices graph with the indices of sorted graph in which order the result has to be printed
    for (int i = 0; i < number_of_vertices; i++) indices[i] = graph[i]->get_index() - vertex_index_increment;

    // launch the graph coloring
    color_graph(graph, number_of_vertices, true, indices);

    // delete the temporary array
    delete [] indices;

}