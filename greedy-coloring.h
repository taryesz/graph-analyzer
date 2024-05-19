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

// this function resets the array of colors (but more efficiently)
// i.e. instead of resetting the gigantic array of colors, even most of those colors haven't been used
// we use a list of used colors and reset only those that were actually changed
void reset_available_colors(list* colored_neighbors, bool* available_colors) {

    // create an iterator
    node* iterator = colored_neighbors->get_head();

    // iterate through the list
    while (iterator != nullptr) {

        // set the color as available
        available_colors[iterator->get_content()] = false;

        // get the next element
        iterator = iterator->get_next();

    }

}

// this function colors all the vertices in the graph so that no 2 adjacent vertices have the same color
void color_the_graph_greedily(vertex** graph, const int number_of_vertices) {

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

    // iterate through the graph starting with the second vertex
    for (int i = 1; i < number_of_vertices; i++) {

        // reset the available colors array
        reset_available_colors(colored_neighbors, available_colors);

        // clear the list of colored neighbors
        colored_neighbors->clear();

        // get the first neighbor of the current vertex
        node* neighbor = graph[i]->get_neighbors()->get_head();

        // iterate through the list of neighbors of the current vertex
        while (neighbor != nullptr) {

            // get the index of the neighbor
            int neighbor_index = neighbor->get_content() - vertex_index_increment; // Assuming 1-based indexing

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

    // print the result
    for (int i = 0; i < number_of_vertices; i++) printf("%d ", result_colors[i]);
    printf("\n");

    delete [] result_colors;    // clean up memory
    delete [] available_colors; // clean up memory

}
