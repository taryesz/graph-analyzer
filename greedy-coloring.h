//void perform_greedy_coloring(vertex* graph, const int number_of_vertices) {
//
//    int color = 1;
//
//    auto* used_colors = new list();
//
//    int colored_vertices[number_of_vertices];
//
//    for (int i = 0; i < number_of_vertices; i++) {
//
//        if (i > 0) {
//
//            if (!graph[i].get_degree()) {
//                color = used_colors->get_tail()->get_content();
//            }
//            else {
//                node *neighbor = graph[i].get_neighbors()->get_head();
//
//                while (neighbor != nullptr) {
//
//                    if (neighbor->get_content() < graph[i].get_index()) {
//                        color = used_colors->get_tail()->get_content() + 1;
//                        break;
//                    }
//
//                    neighbor = neighbor->get_next();
//
//                }
//            }
//
//        }
//
//        colored_vertices[i] = color;
//        used_colors->push(color);
//
//        color = used_colors->get_head()->get_content();
//
//        node* iterator = used_colors->get_head();
//        printf("\nlist: ");
//        while (iterator != nullptr) {
//            printf("%d ", iterator->get_content());
//            iterator = iterator->get_next();
//        }
//        printf("\n");
//
//    }
//
//    for (int i = 0; i < number_of_vertices; i++) printf("%d ", colored_vertices[i]);
//    printf("\n");
//
//}

bool check_if_color_used(int color, list* used_colors) {

    node* iterator = used_colors->get_head();

    while (iterator != nullptr) {

        if (iterator->get_content() == color) return true;

        iterator = iterator->get_next();
    }

    return false;

}

void perform_greedy_coloring(vertex* graph, const int number_of_vertices) {

    int color = 1;

    auto* used_colors = new list();

    int colored_vertices[number_of_vertices];

    for (int i = 0; i < number_of_vertices; i++) {

        if (i > 0) {

            if (!graph[i].get_degree()) {
                color = used_colors->get_tail()->get_content(); // use the first color
            }
            else {

                node *neighbor = graph[i].get_neighbors()->get_head();

                while (neighbor != nullptr) {

                    if (neighbor->get_content() < graph[i].get_index()) {

                        if (check_if_color_used(colored_vertices[neighbor->get_content() - vertex_index_increment], used_colors)) {

                            // check if the neighbor and the actual vertex have a common neighbor
                            // if so, add new color (+1)
                            // else, use the first from the list

                            color = colored_vertices[neighbor->get_content() - vertex_index_increment] + 1;

                        }
                        else color = used_colors->get_tail()->get_content();

                    }

                    neighbor = neighbor->get_next();

                }

            }

        }

        colored_vertices[i] = color;

        if (!check_if_color_used(color, used_colors)) used_colors->push(color); // save the unused color

        color = used_colors->get_tail()->get_content(); // get the first color used

    }

    for (int i = 0; i < number_of_vertices; i++) printf("%d ", colored_vertices[i]);
    printf("\n");

}