/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** find_errors
*/

#include "../include/struct.h"

void print_fail(graph_t *graph)
{
    print("#number_of_robots\n");
    print("%i\n", graph->nb_robot);
}

void find_if_error(graph_t *graph, int i)
{
    if (graph->st_tu == 0)
        graph->er = i;
    if (graph->nb_end == 0 || graph->nb_start == 0)
        graph->er = graph->st_tu;
}
