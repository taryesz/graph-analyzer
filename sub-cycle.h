// this function is the implementation of the DFS traversal which visits the neighboring vertices of a vertex
void traverse_graph(vertex* graph, vertex current_vertex, bool* visited_vertices, int starting_vertex_index, int depth, int* result) {

    // create the iterator through the neighbors list
    node* neighbor = current_vertex.get_neighbors()->get_head();

//    if (!depth) {
//
//        printf("reached max depth (4)\n");
//
//        printf("%d --- %d\n", neighbor->get_content(), starting_vertex_index);
//        if (neighbor->get_content() == starting_vertex_index) ++(*result);
//        printf("returning (result = %d)\n", *result);
//        return;
//
//    }

    // iterate through the neighbor list
    while (neighbor != nullptr) {

        // get the current neighbor's index
        const int checked_vertex_index = neighbor->get_content();

        printf("current neighbor: v%d\n", checked_vertex_index);

        // if the neighbor has not been visited yet ...
        if (!visited_vertices[checked_vertex_index - vertex_index_increment]) {

            // visit the neighbor
            visited_vertices[checked_vertex_index - vertex_index_increment] = true;

            printf("launching traversal on the current neighbor: v%d\n", checked_vertex_index);

            // launch the traversal mechanism on the neighbor
            traverse_graph(graph, graph[checked_vertex_index - vertex_index_increment], visited_vertices, starting_vertex_index, depth-1, result);

        }
        else {

            if (visited_vertices[checked_vertex_index - vertex_index_increment] && checked_vertex_index == starting_vertex_index) {
               if (!depth) {
                   ++(*result);
                   return;
               }
            }

        }

        // get the next neighbor's index
        neighbor = neighbor->get_next();

        printf("grabbing the next neighbor\n");

    }

}

// this function checks how many parts the graph consists of
int get_number_of_subcycles(vertex* graph, const int number_of_vertices) {

    // create a variable that stores the information about the number of parts in the graph
    int result = 0;

    // create an array to store the information about visited vertices
    bool visited_vertices[number_of_vertices];

    // fill in the visited array with false's by default
    for (int i = 0; i < number_of_vertices; i++) visited_vertices[i] = false;

    // iterate through the whole array of vertices
    for (int vertex_counter = 0; vertex_counter < number_of_vertices; vertex_counter++) {

        // visit the current vertex
        visited_vertices[vertex_counter] = true;

        printf("visited the starting vertex (v%d) and launching traversal\n", vertex_counter + vertex_index_increment);

        // check the vertex's neighbors
        traverse_graph(graph, graph[vertex_counter], visited_vertices, vertex_counter + vertex_index_increment, subcycle_size, &result);

        printf("clearing the visited array\n");

        for (int i = 0; i < number_of_vertices; i++) visited_vertices[i] = false;

    }

    printf("%d\n", result); // print the result
    return result;          // return the result

}