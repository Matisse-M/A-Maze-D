/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** free_func
*/

#include "../include/struct.h"

void free_func(graph_t *graph)
{
    if (graph->all != NULL) {
        for (int i = 0; graph->all[i] != NULL; i++) {
            free(graph->all[i]);
        }
        free(graph->all);
    }
    if (graph->room != NULL) {
        for (int j = 0; graph->room[j]; j++)
            free(graph->room[j]);
        free(graph->room);
    }
    if (graph->tunel != NULL) {
        for (int k = 0; graph->tunel[k]; k++)
            free(graph->tunel[k]);
        free(graph->tunel);
    }
}
