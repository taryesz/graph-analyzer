// this function finds the maximum element in the array
void find_max(const int* distance, const int number_of_vertices, int* max_distance) {
    for (int i = 0; i < number_of_vertices; i++) {
        if (distance[i] > *max_distance) *max_distance = distance[i];
    }
}

// this function is the implementation of the bfs traversal of a graph
int bfs(vertex** graph, int current_vertex_index, const int number_of_vertices, const int number_of_vertices_in_current_component) {

    // create an array to store the information about the distance between the current vertex and the rest of them
    int* distance = new int[number_of_vertices];

    // initiate the array with the default data (0)
    initiate_array(distance, number_of_vertices, 0);

    // create an array to store the information about visited vertices
    bool* visited_vertices = new bool[number_of_vertices];

    // initiate the array with the default data (false)
    initiate_array(visited_vertices, number_of_vertices, false);

    // create a queue
    int* queue = new int[number_of_vertices];

    int front = 0, rear = 0;

    // visit the current vertex
    visited_vertices[current_vertex_index] = true;

    // enqueue the current vertex
    queue[rear++] = current_vertex_index;

    // counter to keep track of vertices added to the queue
    int added_vertices_counter = 1;

    // while there are elements on the queue ...
    while (front != rear) {

        // dequeue a vertex from queue
        current_vertex_index = queue[front++];

        // create an iterator through the list of neighbors of the current vertex
        node* neighbor = graph[current_vertex_index]->get_neighbors()->get_head();

        // iterate through the list of neighbors
        while (neighbor != nullptr) {

            // get the current neighbor's index
            int neighbor_index = neighbor->get_content() - vertex_index_increment;

            // if the current neighbor hasn't been visited yet ...
            if (!visited_vertices[neighbor_index]) {

                // visit the neighbor
                visited_vertices[neighbor_index] = true;

                // enqueue the neighbor
                queue[rear++] = neighbor_index;

                // update distance of the neighbor
                distance[neighbor_index] = distance[current_vertex_index] + 1;

                // increment the counter
                added_vertices_counter++;

            }

            // get the next neighbor
            neighbor = neighbor->get_next();

        }

        // check if all vertices from the connected component have been added
        // then there is no point in traversing the whole graph since all of its vertices were already processed
        if (added_vertices_counter == number_of_vertices) break;

    }

    // find the maximum distance, which represents the eccentricity of the current vertex
    int max_distance = 0;
    find_max(distance, number_of_vertices, &max_distance);

    delete [] queue; // clean memory up
    delete [] distance;
    delete [] visited_vertices;

    return max_distance; // return the eccentricity

}

// this function launches bfs traversal of a graph to find eccentricity of each of its vertices
void get_eccentricity(vertex** graph, const int number_of_vertices) {

    // iterate through the graph
    for (int i = 0; i < number_of_vertices; i++) {

        const int number_of_vertices_in_current_component = graph[i]->get_component();

        // launch the bfs traversal and print the result
        printf("%d ", bfs(graph, i, number_of_vertices, number_of_vertices_in_current_component));

    }

    // print a newline symbol for aesthetic purposes
    printf("\n");

}
