/*
** EPITECH PROJECT, 2024
** B-CPE-200-NAN-2-1-amazed-albane.merian
** File description:
** init_parser
*/

#include "../include/struct.h"

graph_t *init_stru(graph_t *graph)
{
    graph = (graph_t *)my_malloc(graph, sizeof(graph_t));
    graph->all = (char **)my_malloc(graph->all, 32000 * sizeof(char *));
    graph->st_tu = 0;
    graph->is_way = false;
    return graph;
}

static void find_start_tunnel(graph_t *graph, int i)
{
    for (int f = 0; graph->l[f] != '\0'; f++) {
        if (graph->st_tu == 0 && graph->l[f] == '-') {
            graph->st_tu = i;
        }
    }
}

static int check_if_garbage(graph_t *graph, int i)
{
    char *dup = my_strdup(graph->l);
    char **temp = my_str_to_word_array(dup);

    if (i <= 0 || graph->st_tu != 0 || graph->l[0] == '#')
        return 0;
    if (temp[1] == NULL || temp[2] == NULL) {
        graph->er = i;
        return 84;
    }
    return 0;
}

static int check_if(graph_t *graph, int i)
{
    find_start_tunnel(graph, i);
    if (check_if_garbage(graph, i) == 84)
        return -1;
    return 0;
}

static int count_nb_flags(graph_t *graph, int i)
{
    if (graph->l[0] == '#' && graph->l[1] != '#')
        return i;
    if (graph->was_start == 1 && strcmp_my(graph->l, "##end") == 1) {
        graph->er = i;
        return -1;
    }
    graph->was_start = 0;
    if (i == 0 && myis_num(graph->l) == 0)
        return -1;
    if (i == 0)
        graph->nb_robot = my_getnbr(graph->l);
    if (strcmp_my(graph->l, "") == 1) {
        graph->er = i;
        return -1;
    }
    if (check_if(graph, i) == -1)
        return -1;
    graph->all[i] = my_strdup(graph->l);
    i++;
    return i;
}

static int check_start(graph_t *graph, int i)
{
    if (strcmp_my(graph->l, "##start") == 1) {
        graph->nb_start += 1;
        graph->was_start += 1;
        if (graph->nb_start != 1) {
            graph->er = i;
            return 84;
        }
    }
    return 0;
}

static int check_nb_start_end(graph_t *graph, int i)
{
    if (check_start(graph, i) == 84)
        return 84;
    if (graph->was_start == 1) {
        return 0;
    }
    if (strcmp_my(graph->l, "##end") == 1) {
        graph->was_start = 0;
        graph->nb_end += 1;
        if (graph->nb_end != 1) {
            graph->er = i;
            return 84;
        }
    }
    return 0;
}

int getline_input(graph_t *graph)
{
    int i = 0;

    while (1) {
        graph->read = getline(&graph->l, &graph->len, stdin);
        if (graph->l[graph->read - 1] == '\n')
            graph->l[graph->read - 1] = '\0';
        if (graph->read == -1) {
            graph->end = i;
            break;
        }
        remove_comment(graph->l);
        i = count_nb_flags(graph, i);
        if (i == -1)
            return 84;
        if (check_nb_start_end(graph, i) == 84)
            return 0;
    }
    find_if_error(graph, i);
    return 0;
}

int fill_arr(int argc, char **argv, graph_t *graph)
{
    graph = init_stru(graph);
    if (getline_input(graph) == 84) {
        stop_empty_line(graph);
        return 84;
    }
    if (graph->st_tu == 0 || graph->nb_start != 1 || graph->nb_end != 1) {
        handle_empty_tunel(graph);
        return 84;
    }
    graph->dup = my_arrndup(graph->all, 1, graph->st_tu - 1);
    init_room_names(graph);
    if (init_coordinates(graph) == -1) {
        print_fail(graph);
        return 84;
    }
    if (handle_move(graph, argc, argv) == 84)
        return 84;
    return 0;
}
