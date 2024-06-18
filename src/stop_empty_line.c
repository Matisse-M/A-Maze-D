/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** stop_empty_line
*/

#include "../include/struct.h"

void stop_empty_line(graph_t *graph)
{
    print("#number_of_robots\n");
    print("%i\n", graph->nb_robot);
    if (graph->all[1] == NULL)
        return;
    if (graph->st_tu == 0) {
        print("#rooms\n");
        for (int i = 1; i != graph->er; i++)
            print("%s\n", graph->all[i]);
        return;
    }
    for (int i = 1; i != graph->er; i++) {
        if (i == graph->st_tu)
            print("#tunnels\n");
        print("%s\n", graph->all[i]);
    }
    return;
}
