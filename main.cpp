#include <iostream>
#include "vertex.h"
#include "hashmap.h"
#include "array.h"
#include "sort.h"
#include "input.h"
#include "degree-sequence.h"
#include "connectivity.h"
#include "bipartiteness.h"
#include "coloring.h"
#include "complement.h"

int main() {

    // get the number of graphs a user wants to process
    const int number_of_graphs = get_user_input();

    // start the loop of vertex processor
    for (int i = 0; i < number_of_graphs; i++) {

        // get the number of vertices of a graph
        const long long int number_of_vertices = get_user_input();

        // create a graph to store vertices in
        auto** graph = new vertex*[static_cast<size_t>(number_of_vertices)];

        // start the loop of vertices processor
        for (int j = 0; j < number_of_vertices; j++) {

            // create a vertex
            auto* new_vertex = new vertex();

            // get the vertex's degree (i.e. number of its neighbors)
            const int new_vertex_degree = get_user_input();

            // set the vertex's degree
            new_vertex->set_degree(new_vertex_degree);

            // set the vertex's index
            new_vertex->set_index(j + vertex_index_increment);

            // start the loop of adjacency processor
            for (int k = 0; k < new_vertex_degree; k++) {

                // get the next neighbor and add it to the list
                new_vertex->get_neighbors()->push(get_user_input());

            }

            // add the vertex to the graph
            graph[j] = new_vertex;

        }

        // calculate the degree sequence of the graph
        get_degree_sequence(graph, (int) number_of_vertices);

        // check how many parts the graph consists of
        get_connectivity_number(graph, (int) number_of_vertices);

        // check if the graph is bipartite
        is_bipartite(graph, (int) number_of_vertices);

        printf("?\n");
        printf("?\n");

        // get the sequence of colors of each vertex using greedy algorithm
        color_graph(graph, (int) number_of_vertices);

        // get the sequence of colors of each vertex using LF algorithm
        color_graph_largest_first(graph, (int) number_of_vertices);

        printf("?\n");
        printf("?\n");

        // calculate the number of missing edges to make the graph a full one
        get_number_of_edge_complement(graph, number_of_vertices);

        // delete all the vertices from the graph and the graph itself
        for (int j = 0; j < number_of_vertices; j++) delete graph[j];
        delete [] graph;

    }

    return 0;

}
