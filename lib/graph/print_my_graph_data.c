/*
** EPITECH PROJECT, 2023
** main
** File description:
** Minishell 1
*/

#include <stdlib.h>
#include "graph.h"
#include "../../include/my.h"

static void loop_inside_anthill(link_t *graph, int *x)
{
    for (int i = 0; i < my_structlen(graph->link); i++) {
        if (*x != graph->link[i]->data) {
            *x = graph->data;
            print_my_graph_data(graph->link[i]);
        } else {
            print("%d\n", graph->link[i]->data);
        }
    }
}

void print_my_graph_data(link_t *graph)
{
    static int x = 0;

    print("[%d]:\n", graph->data);
    if (graph->link != NULL) {
        loop_inside_anthill(graph, &x);
    }
}
