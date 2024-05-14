#include <iostream>
#include "classes/vertex.h"
#include "input.h"
#include "degree-sequence.h"
#include "components.h"
#include "complement-graph.h"

int main() {

    // get the number of graphs a user wants to process
    const int number_of_graphs = get_user_input();

    // start the loop of vertex processor
    for (int i = 0; i < number_of_graphs; i++) {

        // get the number of vertices of a vertex
        const int number_of_vertices = get_user_input();

        // create a graph to store vertices in
        vertex graph[number_of_vertices];

        // start the loop of vertices processor
        for (int j = 0; j < number_of_vertices; j++) {

            // create a vertex
            auto* new_vertex = new vertex();

            // create a list to store the adjacent vertices' indexes
            auto* new_vertex_neighbors = new list();

            // get the vertex's degree (i.e. number of its neighbors)
            const int new_vertex_degree = get_user_input();

            // set the vertex's degree
            new_vertex->set_degree(new_vertex_degree);

            // set the vertex's index
            new_vertex->set_index(j + vertex_index_increment);

            // start the loop of adjacency processor
            for (int k = 0; k < new_vertex_degree; k++) {

                // get the next neighbor and add it to the list
                new_vertex_neighbors->push(get_user_input());

            }

            // add the list to the vertex
            new_vertex->set_neighbors(new_vertex_neighbors);

            // add the vertex to the graph
            graph[j] = *new_vertex;

        }

        get_degree_sequence(graph, number_of_vertices); // calculate the degree sequence of the graph
        is_connected(graph, number_of_vertices); // check if the graph is connected
        get_number_of_edge_complement(graph, number_of_vertices); // calculate the number of missing edges to make the graph a full one

    }

    return 0;

}