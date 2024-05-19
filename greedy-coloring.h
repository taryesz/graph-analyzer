int get_next_available_color(const bool* available_colors, const int number_of_vertices) {

    for (int i = 0; i < number_of_vertices; i++) {
        if (!available_colors[i]) {
            return i + vertex_index_increment; // Colors are 1-based
        }
    }
    return number_of_vertices + vertex_index_increment; // Return an out-of-bounds value if no color is available

}

void color_the_graph_greedily(vertex** graph, const int number_of_vertices) {

    int* result_colors = new int[number_of_vertices];

    for (int i = 0; i < number_of_vertices; i++) result_colors[i] = default_value; // Initialize all colors to -1 (indicating no color)

    result_colors[0] = 1; // Set the first vertex's color to 1

    bool* available_colors = new bool[number_of_vertices];

    for (int i = 1; i < number_of_vertices; i++) {

        for (int j = 0; j < number_of_vertices; j++) available_colors[j] = false; // Reset available colors for the current vertex

        node* neighbor = graph[i]->get_neighbors()->get_head();

        while (neighbor != nullptr) {

            int neighbor_index = neighbor->get_content() - vertex_index_increment; // Assuming 1-based indexing

            if (result_colors[neighbor_index] != default_value) available_colors[result_colors[neighbor_index] - vertex_index_increment] = true; // Mark the color as unavailable

            neighbor = neighbor->get_next();
        }

        int color_of_vertex = get_next_available_color(available_colors, number_of_vertices);
        result_colors[i] = color_of_vertex; // Assign the found color to the current vertex

    }

    for (int i = 0; i < number_of_vertices; i++) printf("%d ", result_colors[i]);
    printf("\n");

    delete [] result_colors;
    delete [] available_colors;

}
