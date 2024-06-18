/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** check_all
*/

#include "../include/struct.h"

static void fill_end(graph_t *graph, int i)
{
    char *str = my_strdup(graph->all[i]);
    char **dup = my_str_to_word_array(str);

    graph->val_end = my_strdup(dup[0]);
}

static void fill_start(graph_t *graph, int i)
{
    char *str = my_strdup(graph->all[i]);
    char **dup = my_str_to_word_array(str);

    graph->val_start = my_strdup(dup[0]);
}

int checl_all_two(graph_t *graph, int i)
{
    if (i == 0 && my_isnum(graph->all[i]) == 0) {
        graph->er = i;
        return 84;
    }
    if (strcmp_my(graph->all[i], "##end") == 1) {
        i += 1;
        if (my_str_num(graph->all[i]) == 0) {
            graph->er = i;
            return 84;
        }
        fill_end(graph, i);
        i -= 1;
        graph->nb_end += 1;
        if (graph->nb_start == 0) {
            graph->er = i;
            return 84;
        }
    }
    return 0;
}

int check_all(graph_t *graph, int i)
{
    if (i == 0 && (strcmp_my(graph->all[i], "##start") == 1 ||
        strcmp_my(graph->all[i], "##end") == 1)) {
        graph->er = i;
        return 84;
    }
    if (strcmp_my(graph->all[i], "##start") == 1) {
        i += 1;
        if (my_str_num(graph->all[i]) == 0) {
            graph->er = i;
            return 84;
        }
        fill_start(graph, i);
        i -= 1;
        graph->nb_start += 1;
    }
    if (checl_all_two(graph, i) == 84)
        return 84;
    return 0;
}
