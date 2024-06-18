/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** init_error
*/

#include "../include/struct.h"

void print_error(graph_t *graph)
{
    print("#number_of_robots\n");
    print("%i\n", graph->nb_robot);
    print("#rooms\n");
    for (int i = 0; graph->room[i] != NULL; i++) {
        print("%s\n", graph->room[i]);
    }
    print("#tunnels\n");
    for (int j = 0; graph->tunel[j] != NULL; j++) {
        if (graph->tunel[j][0] != '#')
            print("%s\n", graph->tunel[j]);
    }
}

void handle_empty_tunel(graph_t *graph)
{
    if (graph->nb_start == 0 && graph->nb_end == 0) {
        print("#number_of_robots\n");
        print("%i\n", graph->nb_robot);
        return;
    }
    print("#number_of_robots\n");
    print("%i\n", graph->nb_robot);
    print("#rooms\n");
    if (graph->nb_start != 0 || graph->nb_end != 0) {
        for (int i = 1; i != graph->er; i++)
            print("%s\n", graph->all[i]);
    } else {
        for (int i = 1; i != graph->st_tu; i++)
            print("%s\n", graph->all[i]);
    }
}

void handle_empty_same_coordinates(graph_t *graph)
{
    print("#number_of_robots\n");
    print("%i\n", graph->nb_robot);
    print("#rooms\n");
    for (int i = 0; i != graph->er; i++)
        print("%s\n", graph->dup[i]);
}

void handle_empty_same_name(graph_t *graph)
{
    print("#number_of_robots\n");
    print("%i\n", graph->nb_robot);
    print("#rooms\n");
    for (int i = 1; i != graph->er; i++)
        print("%s\n", graph->all[i]);
}

int init_error(graph_t *graph)
{
    char **dup = NULL;
    int i = 0;

    if (graph->is_error == 2) {
        handle_empty_same_name(graph);
        return 84;
    }
    if (graph->is_error == 1) {
        handle_empty_same_coordinates(graph);
        return 84;
    }
    for (; graph->all[i] != NULL; i++);
    dup = dup_arr(graph->all);
    if (graph->tunel_pos != 0) {
        graph->room = my_arrndup(graph->all, 1, graph->tunel_pos - 1);
        graph->tunel = my_arrndup(dup, graph->tunel_pos, graph->er - 1);
        print_error(graph);
    } else
        handle_empty_tunel(graph);
    return 84;
}
